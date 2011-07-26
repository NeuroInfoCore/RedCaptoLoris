<?php 
class NDB_BVL_Instrument_memory_guided_delay_0 extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "memory_guided_delay_0"; 
		$this->table = "memory_guided_delay_0"; 

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
		$this->form->addElement('text','vn_0','Number of viable trials','');
		$this->form->addElement('select','vn_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt1_0','Saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','srt1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std1_0','Standard deviation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','std1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv1_0','Coefficient of variation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','cv1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt2_0','Saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','srt2_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std2_0','Standard deviation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','std2_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv2_0','Coefficient of variation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','cv2_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqn_0','Number of sequence Errors','');
		$this->form->addElement('select','eseqn_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqper_0','Percent of sequence errors','');
		$this->form->addElement('select','eseqper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipn_0','Number of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipn_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipper_0','Percent of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopn_0','Number of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopn_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopper_0','Percent of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimen_0','Number of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimen_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimeper_0','Percent of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimeper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimen_0','Number of timing errors','');
		$this->form->addElement('select','corretimen_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimeper_0','Percent of timing errors','');
		$this->form->addElement('select','corretimeper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalsen_0','Number of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalsen_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalseper_0','Percent of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalseper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalsen_0','Number of false starts only','');
		$this->form->addElement('select','correfalsen_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalseper_0','Percent of false starts only','');
		$this->form->addElement('select','correfalseper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepn_0','Number of trials with step saccades','');
		$this->form->addElement('select','stepn_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepper_0','Percent of trials with step saccades','');
		$this->form->addElement('select','stepper_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel1_0','Velocity of first saccade','');
		$this->form->addElement('select','vel1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp1_0','Amplitude of the first saccade','');
		$this->form->addElement('select','amp1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel2_0','Velocity of second saccade','');
		$this->form->addElement('select','vel2_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp2_0','Amplitude of the second saccade','');
		$this->form->addElement('select','amp2_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','firstang_0','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','firstang_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fsac_acc_0','Accuracy of the first saccade','');
		$this->form->addElement('select','fsac_acc_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','acc_0','Accuracy of the final fixation to the second target','');
		$this->form->addElement('select','acc_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_t1_0','Accuracy of the closest fixation to T1(most useful)','');
		$this->form->addElement('select','fix_acc_t1_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_0','Accuracy of the closest fixation to T2(most useful)','');
		$this->form->addElement('select','fix_acc_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','plength_acc_0','Path length accuracy (actual/optimal path length)','');
		$this->form->addElement('select','plength_acc_0_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
