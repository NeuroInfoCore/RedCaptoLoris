<?php 
class NDB_BVL_Instrument_antisaccade extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "antisaccade"; 
		$this->table = "antisaccade"; 

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
		$this->form->addElement('text','antisacc_vn','Number of viable trials','');
		$this->form->addElement('select','antisacc_vn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_srt','Saccadic reaction time of correct trials','');
		$this->form->addElement('select','antisacc_srt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_std','Standard deviation of Saccdic reaction time for correct trials','');
		$this->form->addElement('select','antisacc_std_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_cv','Coefficient of variation of correct trials','');
		$this->form->addElement('select','antisacc_cv_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_eper','Percent of express saccades(90-140ms)','');
		$this->form->addElement('select','antisacc_eper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_wn','Number of direction errrors','');
		$this->form->addElement('select','antisacc_wn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_wsrt','Saccadic reaction time of direction errors','');
		$this->form->addElement('select','antisacc_wsrt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_wper','Percent of direction errors','');
		$this->form->addElement('select','antisacc_wper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_rn','Number of corrected direction errors','');
		$this->form->addElement('select','antisacc_rn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_rsrt','Saccadic reaction time of corrective saccades','');
		$this->form->addElement('select','antisacc_rsrt_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_rper','Percent of direction errors that were corrected','');
		$this->form->addElement('select','antisacc_rper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_an','Number of anticipatory saccades(< 90ms)','');
		$this->form->addElement('select','antisacc_an_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_aper','Percent of anticipatory errors','');
		$this->form->addElement('select','antisacc_aper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_stepn','Trials with step saccades','');
		$this->form->addElement('select','antisacc_stepn_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_stepper','Percent of trials with step saccades','');
		$this->form->addElement('select','antisacc_stepper_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_vel','Velocity','');
		$this->form->addElement('select','antisacc_vel_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_amp','Amplitude','');
		$this->form->addElement('select','antisacc_amp_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','antisacc_firstang','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','antisacc_firstang_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
