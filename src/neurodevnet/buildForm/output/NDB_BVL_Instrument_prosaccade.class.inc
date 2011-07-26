<?php 
class NDB_BVL_Instrument_prosaccade extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "prosaccade"; 
		$this->table = "prosaccade"; 

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
		$this->form->addElement('text','prosacc_vn','Number of viable trials','');
		$this->form->addElement('select','prosacc_vn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_srt','Saccadic reaction time of correct trials','');
		$this->form->addElement('select','prosacc_srt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_std','Standard deviation of SRT for correct trials','');
		$this->form->addElement('select','prosacc_std_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_cv','Coefficient of variation of correct trials','');
		$this->form->addElement('select','prosacc_cv_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_eper','Percent of express saccades(90-140ms)','');
		$this->form->addElement('select','prosacc_eper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_wn','Number of direction errors','');
		$this->form->addElement('select','prosacc_wn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_wsrt','Saccadic reaction time of direction errors','');
		$this->form->addElement('select','prosacc_wsrt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_wper','Percent of direction errors','');
		$this->form->addElement('select','prosacc_wper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_rn','Number of corrected direction errors','');
		$this->form->addElement('select','prosacc_rn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_rsrt','Saccadic reaction time of corrective saccades','');
		$this->form->addElement('select','prosacc_rsrt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_rper','Percent of direction errors that were corrected','');
		$this->form->addElement('select','prosacc_rper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_an','Number of anticipatory saccades(< 90ms)','');
		$this->form->addElement('select','prosacc_an_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_aper','Percent of anticipatory errors','');
		$this->form->addElement('select','prosacc_aper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_stepn','Trials with step saccades','');
		$this->form->addElement('select','prosacc_stepn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_stepper','Percent of trials with step saccades','');
		$this->form->addElement('select','prosacc_stepper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_vel','Velocity','');
		$this->form->addElement('select','prosacc_vel_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_amp','Amplitude','');
		$this->form->addElement('select','prosacc_amp_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','prosacc_firstang','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','prosacc_firstang_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
