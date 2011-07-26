/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package neurodevnet.buildForm;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * This class parse a File and places the data in a
 * 
 * @author nicolas
 */
public class FormFileProcess {

    private int lineNumber = 0;

    public FormFileProcess( String inputFile, String outputDirectory ) throws Exception {

        // ************************************************
        // Read the data
        // ************************************************
        BufferedReader br = new BufferedReader( new InputStreamReader( new DataInputStream( new FileInputStream(
                inputFile ) ) ) );

        // ************************************************
        // Put each line found in an Info object
        // ************************************************
        ArrayList<Info> listInfo = getAllInfo( br );
        br.close();

        // ************************************************
        // organise the data found by the form name
        // ************************************************
        HashMap<String, ArrayList<Info>> formsByName = divideByForms( listInfo );

        // ************************************************
        // for each redcap form write the loris form
        // ************************************************
        FormWriter fw = new FormWriter( outputDirectory );

        for ( String key : formsByName.keySet() ) {
            fw.writeForm( key, formsByName.get( key ) );
        }
    }

    /* transform each line found in the input file into an object and return an ArrayList of those objects
     * those objects called Info are also responsible to transform the data they found into loris data
     */
    private ArrayList<Info> getAllInfo( BufferedReader br ) throws Exception {

        String line = "";

        ArrayList<Info> al = new ArrayList<Info>();

        // for each line of the file
        while ( ( line = br.readLine() ) != null ) {
            lineNumber++;

            // first line is of no interest
            if ( lineNumber != 1 ) {

                // format the line in a correct way
                line = doLineOperations( line );

                // place the line in an Info object
                Info info = getInfo( line );

                // ***********************************************************
                // Transform RedCap data into Loris data
                // ***********************************************************
                info.createlorisField();

                al.add( info );
            }
        }
        return al;
    }

    // format each line so it will have 15 tokens and can easily be read and manipulate
    private Info getInfo( String line ) throws Exception {

        // if the line finish with , add n to it so it can be split
        if ( line.charAt( line.length() - 1 ) == ',' ) {
            line += "n";
        }

        // all fields for 1 line should be 15 tokens
        String[] fieldTable = line.split( "," );

        // we should always have 15 tokens or something went wrong
        if ( fieldTable.length != 15 ) {
            throw new Exception( line + " doesn't have 15 token but: " + fieldTable.length );
        }

        // lets populate the object that keeps the data
        return new Info( fieldTable[0], fieldTable[1], fieldTable[2], fieldTable[3], fieldTable[4], fieldTable[5],
                fieldTable[6], fieldTable[7], fieldTable[8], fieldTable[9], fieldTable[10], fieldTable[11],
                fieldTable[12], fieldTable[13], fieldTable[14] );
    }

    private String doLineOperations( String line ) throws Exception {

        // replace ' by \'
        line = line.replace( "\'", "\\\'" );
        // replace "" by nothing
        line = line.replace( "\"\"", "" );

        if ( line.indexOf( "\"" ) != -1 ) {
            line = replaceSpecialCharacters( line );
        }

        // replace " by nothing
        line = line.replace( "\"", "" );

        return line;
    }

    /*
     * Anything between an Opening character " and Closing character " should never contain the symbol  ,   when something
     * is found between those symbol replace the symbol , by ; so we will able to tokenize (split) the string in 15
     * pieces using the character ,
     */
    private String replaceSpecialCharacters( String text ) throws Exception {

        String part1 = text.substring( 0, text.indexOf( "\"" ) );
        // first "
        String specialCha1 = text.substring( text.indexOf( "\"" ), text.indexOf( "\"" ) + 1 );
        String part2 = text.substring( text.indexOf( "\"" ) + 1 );

        // if no closing " for an opening " then we have a problem
        if ( part2.indexOf( "\"" ) == -1 ) {
            throw new Exception( "Closing character \" was not found in the file" );
        }

        // this is the part which we dont want to have the caracter ,
        String part2a = part2.substring( 0, part2.indexOf( "\"" ) );
        // second "
        String specialCha2 = part2.substring( part2.indexOf( "\"" ), part2.indexOf( "\"" ) + 1 );
        String part2b = part2.substring( part2.indexOf( "\"" ) + 1 );

        // lets check if part2b got the character "
        if ( part2b.indexOf( "\"" ) != -1 ) {
            // recursion call since we might have more than one opening and closing "
            part2b = replaceSpecialCharacters( part2b );
        }

        // return same text as received except that is present between " " character , been changed by ;
        return part1 + specialCha1 + part2a.replace( ",", ";" ) + specialCha2 + part2b;
    }

    // divide the ArrayList<Info> found into many ArrayList<Info>, 1 per form
    private HashMap<String, ArrayList<Info>> divideByForms( ArrayList<Info> listInfo ) {

        String formName = "";

        HashMap<String, ArrayList<Info>> formsByName = new HashMap<String, ArrayList<Info>>();

        ArrayList<Info> formInfo = null;

        for ( Info info : listInfo ) {

            if ( formName.equalsIgnoreCase( info.getFormName() ) ) {

                formInfo.add( info );
            } else {

                formName = info.getFormName();
                formInfo = new ArrayList<Info>();
                formsByName.put( formName, formInfo );
            }
        }
        return formsByName;
    }

}