<?php 
class NDB_BVL_Instrument_memory_guided_delay_1200 extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "memory_guided_delay_1200"; 
		$this->table = "memory_guided_delay_1200"; 

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
		$this->form->addElement('text','vn_1200','Number of viable trials','');
		$this->form->addElement('select','vn_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt1_1200','Saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','srt1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std1_1200','Standard deviation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','std1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv1_1200','Coefficient of variation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','cv1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt2_1200','Saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','srt2_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std2_1200','Standard deviation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','std2_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv2_1200','Coefficient of variation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','cv2_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqn_1200','Number of sequence Errors','');
		$this->form->addElement('select','eseqn_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqper_1200','Percent of sequence errors','');
		$this->form->addElement('select','eseqper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipn_1200','Number of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipn_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipper_1200','Percent of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopn_1200','Number of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopn_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopper_1200','Percent of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimen_1200','Number of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimen_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimeper_1200','Percent of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimeper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimen_1200','Number of timing errors','');
		$this->form->addElement('select','corretimen_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimeper_1200','Percent of timing errors','');
		$this->form->addElement('select','corretimeper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalsen_1200','Number of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalsen_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalseper_1200','Percent of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalseper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalsen_1200','Number of false starts only','');
		$this->form->addElement('select','correfalsen_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalseper_1200','Percent of false starts only','');
		$this->form->addElement('select','correfalseper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepn_1200','Number of trials with step saccades','');
		$this->form->addElement('select','stepn_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepper_1200','Percent of trials with step saccades','');
		$this->form->addElement('select','stepper_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel1_1200','Velocity of first saccade','');
		$this->form->addElement('select','vel1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp1_1200','Amplitude of the first saccade','');
		$this->form->addElement('select','amp1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel2_1200','Velocity of second saccade','');
		$this->form->addElement('select','vel2_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp2_1200','Amplitude of the second saccade','');
		$this->form->addElement('select','amp2_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','firstang_1200','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','firstang_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fsac_acc_1200','Accuracy of the first saccade','');
		$this->form->addElement('select','fsac_acc_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','acc_1200','Accuracy of the final fixation to the second target','');
		$this->form->addElement('select','acc_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_t1_1200','Accuracy of the closest fixation to T1(most useful)','');
		$this->form->addElement('select','fix_acc_t1_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_1200','Accuracy of the closest fixation to T2(most useful)','');
		$this->form->addElement('select','fix_acc_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','plength_acc_1200','Path length accuracy (actual/optimal path length)','');
		$this->form->addElement('select','plength_acc_1200_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
