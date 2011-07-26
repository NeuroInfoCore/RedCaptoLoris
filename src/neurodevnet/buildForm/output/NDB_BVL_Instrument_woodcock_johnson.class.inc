<?php 
class NDB_BVL_Instrument_woodcock_johnson extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "woodcock_johnson"; 
		$this->table = "woodcock_johnson"; 

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
		$this->form->addElement('text','wj18b_raw','Number series raw score','');
		$this->form->addElement('select','wj18b_raw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wjtotalraw','Total # correct (18a+18b) raw score','');
		$this->form->addElement('select','wjtotalraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wjstd','Standard Score','');
		$this->form->addElement('select','wjstd_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
