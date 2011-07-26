<?php 
class NDB_BVL_Instrument_working_memory_test_battery extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "working_memory_test_battery"; 
		$this->table = "working_memory_test_battery"; 

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
		$this->form->addElement('text','wmtb_blockraw','Block raw score','');
		$this->form->addElement('select','wmtb_blockraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wmtb_digit_ss','Digit standard score','');
		$this->form->addElement('select','wmtb_digit_ss_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wmtb_block_ss','Block standard score','');
		$this->form->addElement('select','wmtb_block_ss_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wmtb_dig_span','Digit span score','');
		$this->form->addElement('select','wmtb_dig_span_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','wmtb_block_span','Block span score','');
		$this->form->addElement('select','wmtb_block_span_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
