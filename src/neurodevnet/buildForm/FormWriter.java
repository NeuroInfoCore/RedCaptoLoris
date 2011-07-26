package neurodevnet.buildForm;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * @author nicolas
 */

public class FormWriter {

    private BufferedWriter out = null;
    private String outputDirectory = "";

    public FormWriter( String outputDirectory ) {
        this.outputDirectory = outputDirectory;
    }

    public void writeForm( String formName, ArrayList<Info> infos ) throws IOException {
        out = new BufferedWriter( new FileWriter( outputDirectory + "NDB_BVL_Instrument_" + formName + ".class.inc" ) );

        String allLorisFields = "";
        ArrayList<String> dateTimeFields = new ArrayList<String>();

        for ( Info info : infos ) {

            allLorisFields = allLorisFields + info.getLorisField();

            // rule used to find a redcap date field
            if ( info.getFieldType().equalsIgnoreCase( "text" ) && info.getTextValidation().indexOf( "date" ) != -1 ) {

                dateTimeFields.add( info.getFieldName() );
            }
        }

        // first part of the php file
        out.write( getBeginForm( formName, dateTimeFields ) );

        // all Loris fields for that form
        out.write( allLorisFields );

        // last part of the php file
        out.write( getEndForm() );
        out.close();

        /*
         * extra add the sql queries needed to put the instrument in the database we will still miss 1 table to create
         * with **quickform_parser.php** and **generate_tables_sql.php**
         */
        writeSQLqueries( formName );

    }

    private String getBeginForm( String instrumentName, ArrayList<String> dateTimeFields ) {
        StringBuffer sb = new StringBuffer();
        sb.append( "<?php \n" );
        sb.append( "class NDB_BVL_Instrument_" + instrumentName + " extends NDB_BVL_Instrument {\n" );
        sb.append( "\n \n" );
        sb.append( "\tfunction setup($commentID, $page){ \n" );
        sb.append( "\t\t$this->formType=\"XIN\"; \n" );
        sb.append( "\t\t$this->form = new HTML_Quickform('test_form'); \n" );
        sb.append( "\n" );
        sb.append( "\t\t$this->testName = \"" + instrumentName + "\"; \n" );
        sb.append( "\t\t$this->table = \"" + instrumentName + "\"; \n" );
        sb.append( "\n" );
        sb.append( "\t\t$this->commentID = $commentID;  \n" );
        sb.append( "\n" );
        sb.append( "\t\t$this->dateTimeFields=array(" );

        for ( int i = 0; i < dateTimeFields.size(); i++ ) {
            sb.append( "\"" + dateTimeFields.get( i ) + "\"" );

            if ( i != dateTimeFields.size() - 1 ) {
                sb.append( "," );
            }
        }

        sb.append( "); \n" );
        sb.append( "\n" );
        sb.append( "\t\t$db =& Database::singleton(); \n" );
        sb.append( "\t\tif(PEAR::isError($db)) { \n" );
        sb.append( "\t\t\treturn PEAR::raiseError (\"Could not connect to database: \".$db->getMessage()); \n" );
        sb.append( "\t\t}\n" );
        sb.append( "\t\t$this->_setupForm(); \n" );
        sb.append( "\t} \n\n" );
        sb.append( "\tfunction _setupForm(){ \n" );
        sb.append( "\t\t$this->_main(); \n" );
        sb.append( "\t} \n\n" );
        sb.append( "\tfunction _main(){ \n" );

        return sb.toString();
    }

    private String getEndForm() {
        StringBuffer sb = new StringBuffer();
        sb.append( "    } \n" );
        sb.append( "} \n" );
        sb.append( "?> \n" );

        return sb.toString();
    }

    // make some of the sql queries for the database
    private void writeSQLqueries( String formName ) throws IOException {
        out = new BufferedWriter( new FileWriter( outputDirectory + "sql/" + formName + ".sql" ) );
        out.write( "INSERT INTO test_names VALUES ('', '" + formName + "', '" + formName + " data', '0', '1', NULL);\n" );
        out.write( "INSERT INTO instrument_subtests VALUES('', '" + formName + "y', '" + formName
                + "_page1', 'Page 1', 1);\n" );
        out.write( "INSERT INTO test_battery VALUES ('', '" + formName + "', '0', '0', 'Y', 'Visit', '1', NULL);\n" );
        out.close();
    }

}
