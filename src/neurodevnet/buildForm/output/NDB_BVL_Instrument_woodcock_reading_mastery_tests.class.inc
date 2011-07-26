<?php 
class NDB_BVL_Instrument_woodcock_reading_mastery_tests extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "woodcock_reading_mastery_tests"; 
		$this->table = "woodcock_reading_mastery_tests"; 

		$this->commentID = $commentID;  

		$this->dateTimeFields=array(); 

		$db =& Database::singleton(); 
		if(PEAR::isError($db)) { 
			return PEAR::raiseError ("Could not connect to database: ".$db->getMessage()); 
		}
		$this->_setupForm(); 
	} 

	function _setupForm(){ 
		$this->_main(); 
	} 

	function _main(){ 
		$this->form->addElement('text','wrmt_wordid_std','Word Identification standard score','');
		$this->form->addElement('select','wrmt_wordid_std_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wrmt_wordid_per','Word Identification percentile rank','');
		$this->form->addElement('select','wrmt_wordid_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
