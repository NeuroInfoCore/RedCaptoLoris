<?php 
class NDB_BVL_Instrument_memory_guided_delay_600 extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "memory_guided_delay_600"; 
		$this->table = "memory_guided_delay_600"; 

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
		$this->form->addElement('text','vn_600','Number of viable trials','');
		$this->form->addElement('select','vn_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt1_600','Saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','srt1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std1_600','Standard deviation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','std1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv1_600','Coefficient of variation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','cv1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt2_600','Saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','srt2_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std2_600','Standard deviation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','std2_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv2_600','Coefficient of variation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','cv2_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqn_600','Number of sequence Errors','');
		$this->form->addElement('select','eseqn_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqper_600','Percent of sequence errors','');
		$this->form->addElement('select','eseqper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipn_600','Number of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipn_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipper_600','Percent of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopn_600','Number of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopn_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopper_600','Percent of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimen_600','Number of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimen_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimeper_600','Percent of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimeper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimen_600','Number of timing errors','');
		$this->form->addElement('select','corretimen_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimeper_600','Percent of timing errors','');
		$this->form->addElement('select','corretimeper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalsen_600','Number of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalsen_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalseper_600','Percent of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalseper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalsen_600','Number of false starts only','');
		$this->form->addElement('select','correfalsen_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalseper_600','Percent of false starts only','');
		$this->form->addElement('select','correfalseper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepn_600','Number of trials with step saccades','');
		$this->form->addElement('select','stepn_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepper_600','Percent of trials with step saccades','');
		$this->form->addElement('select','stepper_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel1_600','Velocity of first saccade','');
		$this->form->addElement('select','vel1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp1_600','Amplitude of the first saccade','');
		$this->form->addElement('select','amp1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel2_600','Velocity of second saccade','');
		$this->form->addElement('select','vel2_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp2_600','Amplitude of the second saccade','');
		$this->form->addElement('select','amp2_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','firstang_600','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','firstang_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fsac_acc_600','Accuracy of the first saccade','');
		$this->form->addElement('select','fsac_acc_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','acc_600','Accuracy of the final fixation to the second target','');
		$this->form->addElement('select','acc_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_t1_600','Accuracy of the closest fixation to T1(most useful)','');
		$this->form->addElement('select','fix_acc_t1_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_600','Accuracy of the closest fixation to T2(most useful)','');
		$this->form->addElement('select','fix_acc_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','plength_acc_600','Path length accuracy (actual/optimal path length)','');
		$this->form->addElement('select','plength_acc_600_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
