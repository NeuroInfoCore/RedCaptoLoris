<?php 
class NDB_BVL_Instrument_parent_brief extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "parent_brief"; 
		$this->table = "parent_brief"; 

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
		$this->form->addElement('text','b_inhibraw','Inhibit raw score','');
		$this->form->addElement('select','b_inhibraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_shiftraw','Shift raw score','');
		$this->form->addElement('select','b_shiftraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_emoraw','Emotional control raw score','');
		$this->form->addElement('select','b_emoraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_briraw','Behavioural regulation index raw score','');
		$this->form->addElement('select','b_briraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_initraw','Initiate raw score','');
		$this->form->addElement('select','b_initraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_wmraw','Working memory raw score','');
		$this->form->addElement('select','b_wmraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_planraw','Plan/organize raw score','');
		$this->form->addElement('select','b_planraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_orgraw','Organization of materials raw score','');
		$this->form->addElement('select','b_orgraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_monraw','Monitor raw score','');
		$this->form->addElement('select','b_monraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_miraw','Metacognitive index raw score','');
		$this->form->addElement('select','b_miraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_gecraw','Global executive composite raw score','');
		$this->form->addElement('select','b_gecraw_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_inhibit_t','Inhibit T score','');
		$this->form->addElement('select','b_inhibit_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_shift_t','Shift T score','');
		$this->form->addElement('select','b_shift_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_emotion_t','Emotional control T score','');
		$this->form->addElement('select','b_emotion_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_bri_t','Behavioural regulation index T score','');
		$this->form->addElement('select','b_bri_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_initiate_t','Initiate T score','');
		$this->form->addElement('select','b_initiate_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_wm_t','Working memory T score','');
		$this->form->addElement('select','b_wm_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_plan_t','Plan/organize T score','');
		$this->form->addElement('select','b_plan_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_orgmat_t','Organization of materials T score','');
		$this->form->addElement('select','b_orgmat_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_monitor_t','Monitor T score','');
		$this->form->addElement('select','b_monitor_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_mi_t','Metacognitive index T score','');
		$this->form->addElement('select','b_mi_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_gec_t','Global executive composite T score','');
		$this->form->addElement('select','b_gec_t_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_inhibit_per','Inhibit percentile rank','');
		$this->form->addElement('select','b_inhibit_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_shift_per','Shift percentile rank','');
		$this->form->addElement('select','b_shift_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_emotion_per','Emotion percentile rank','');
		$this->form->addElement('select','b_emotion_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_bri_per','Behavioural regulation index percentile rank','');
		$this->form->addElement('select','b_bri_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_initiate_per','Initiate percentile rank','');
		$this->form->addElement('select','b_initiate_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_wm_per','Working memory percentile rank','');
		$this->form->addElement('select','b_wm_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_plan_per','Plan percentile rank','');
		$this->form->addElement('select','b_plan_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_org_per','Organization of materials percentile rank','');
		$this->form->addElement('select','b_org_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_mon_per','Monitor percentile rank','');
		$this->form->addElement('select','b_mon_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_mi_per','Metacognitive index percentile rank','');
		$this->form->addElement('select','b_mi_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','b_gec_per','Global executive composite percentile rank','');
		$this->form->addElement('select','b_gec_per_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
