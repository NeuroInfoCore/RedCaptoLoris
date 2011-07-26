package neurodevnet.buildForm;

/**
 * @author nicolas
 */
public class Main {

    public static void main( String[] args ) throws Exception {

        String inputFormName = "formInfo.cvs";

        // input directory
        String inputDirectory = "./src/neurodevnet/buildForm/input/";

        // output directory to place generate php files
        String outputDirectory = "./src/neurodevnet/buildForm/output/";

        // makes the Loris Forms
        new FormFileProcess( inputDirectory + inputFormName, outputDirectory );
        
        System.out.println("Done, files can be found in the output directory");
    }
}