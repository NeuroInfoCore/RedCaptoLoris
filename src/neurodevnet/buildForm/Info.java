package neurodevnet.buildForm;

/**
 * @author nicolas
 */
public class Info {

    // REDCAP
    // All those field were found in the input File and represent information on the data
    private String fieldName = "";
    private String formName = "";
    private String sectionHeader = "";
    private String fieldType = "";
    private String fieldLabel = "";
    private String choices = "";
    private String fieldNote = "";
    private String textValidation = "";
    private String textValidationMin = "";
    private String textValidationMax = "";
    private String identifier = "";
    private String branchingLogic = "";
    private String requiField = "";
    private String customAlignment = "";
    private String questionNumber = "";

    // LORIS field
    private String lorisField = "";

    public Info( String fieldName, String formName, String sectionHeader, String fieldType, String fieldLabel,
            String choices, String fieldNote, String textValidation, String textValidationMin,
            String textValidationMax, String identifier, String branchingLogic, String requiField,
            String customAlignment, String questionNumber ) {
        super();
        this.fieldName = fieldName;
        this.formName = formName;
        this.sectionHeader = sectionHeader;
        this.fieldType = fieldType;
        this.fieldLabel = fieldLabel;
        this.choices = choices;
        this.fieldNote = fieldNote;
        this.textValidation = textValidation;
        this.textValidationMin = textValidationMin;
        this.textValidationMax = textValidationMax;
        this.identifier = identifier;
        this.branchingLogic = branchingLogic;
        this.requiField = requiField;
        this.customAlignment = customAlignment;
        this.questionNumber = questionNumber;
    }

    public String getFieldName() {
        return fieldName;
    }

    public String getFormName() {
        return formName;
    }

    public String getSectionHeader() {
        return sectionHeader;
    }

    public String getFieldType() {
        return fieldType;
    }

    public String getFieldLabel() {
        return fieldLabel;
    }

    public String getChoices() {
        return choices;
    }

    public String getFieldNote() {
        return fieldNote;
    }

    public String getTextValidation() {
        return textValidation;
    }

    public String getTextValidationMin() {
        return textValidationMin;
    }

    public String getTextValidationMax() {
        return textValidationMax;
    }

    public String getIdentifier() {
        return identifier;
    }

    public String getBranchingLogic() {
        return branchingLogic;
    }

    public String getRequiField() {
        return requiField;
    }

    public String getCustomAlignment() {
        return customAlignment;
    }

    public String getQuestionNumber() {
        return questionNumber;
    }

    public String getLorisField() {
        return lorisField;
    }

    public void createlorisField() throws Exception {

        // Loris Date Field
        if ( fieldType.equalsIgnoreCase( "text" ) && textValidation.indexOf( "date" ) != -1 ) {

            lorisField = "\t\t$this->addDateElement(\"" + fieldName + "\", \"" + fieldLabel + "\");\n";
        }
        // Loris Text Field
        else if ( fieldType.equalsIgnoreCase( "text" ) || fieldType.equalsIgnoreCase( "calc" ) ) {

            lorisField = "\t\t$this->form->addElement('text','" + fieldName + "','" + fieldLabel + "','');\n"
                    + getStatus();

        }
        // Loris Checkbox field
        else if ( fieldType.equalsIgnoreCase( "checkbox" ) ) {

            lorisField = getCheckboxChoicesInfo( choices, fieldName, fieldLabel ) + getStatus();
        }
        // Loris Select field
        else if ( fieldType.equalsIgnoreCase( "radio" ) || fieldType.equalsIgnoreCase( "dropdown" ) ) {

            // we need to find all choices
            String lorisChoices = getSelectChoicesInfo( choices );

            lorisField = "\t\t$this->form->addElement('select','" + fieldName + "','" + fieldLabel
                    + "',array(null => ''," + lorisChoices + "));\n" + getStatus();

        }
        // we are not supposed to have other type of field from redcap
        else {
            throw new Exception( "Unknow type found: " + fieldType );
        }
    }

    // changes choices found in redcap to loris choices
    private String getSelectChoicesInfo( String lineChoices ) {

        String formatChoices = "";

        lineChoices = lineChoices.replace( "|", "-,-" );

        // divide in options
        String[] choices = lineChoices.split( "-,-" );

        for ( int i = 0; i < choices.length; i++ ) {

            String c = choices[i];

            String[] nameToValue = c.split( ";" );
            String name = nameToValue[0].trim();
            String value = nameToValue[1].trim();

            formatChoices = formatChoices + "'" + name + "' =>'" + value + "'";

            if ( i != choices.length - 1 ) {
                formatChoices = formatChoices + ",";
            }
        }
        return formatChoices;
    }

    private String getCheckboxChoicesInfo( String lineChoices, String fieldName, String fieldLabel ) {

        String formatChoices = "";

        lineChoices = lineChoices.replace( "|", "-,-" );

        // divide in options
        String[] choices = lineChoices.split( "-,-" );

        for ( int i = 0; i < choices.length; i++ ) {

            String c = choices[i];

            String[] nameToValue = c.split( ";" );
            String name = nameToValue[0].trim();
            String value = nameToValue[1].trim();

            if ( i == 0 ) {
                formatChoices = formatChoices + "\t\t$this->form->addElement('advcheckbox','" + fieldName + i + "','"
                        + fieldLabel + "','" + value + "','" + name + "'); \n";
            } else {
                formatChoices = formatChoices + "\t\t$this->form->addElement('advcheckbox','" + fieldName + i
                        + "','','" + value + "','" + name + "');\n";
            }
        }
        return formatChoices;
    }

    private String getStatus() {

        String status = "";
        // if we have some branching logic
        if ( !branchingLogic.equals( "" ) ) {

            // not answered option + not applicable
            status = lorisField + "\t\t$this->form->addElement('select','" + fieldName + "_status','" + "Status"
                    + "',array(null => ''," + "'not_answered' =>'Not Answered','not_applicable' =>'Not Applicable'"
                    + "));\n";

        } else {
            // not answered option + not applicable
            status = lorisField + "\t\t$this->form->addElement('select','" + fieldName + "_status','" + "Status"
                    + "',array(null => ''," + "'not_answered' =>'Not Answered'" + "));\n";
        }
        return status;
    }

}