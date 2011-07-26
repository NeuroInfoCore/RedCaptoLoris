<?php 
class NDB_BVL_Instrument_memory_guided_delay_1800 extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "memory_guided_delay_1800"; 
		$this->table = "memory_guided_delay_1800"; 

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
		$this->form->addElement('text','vn_1800','Number of viable trials','');
		$this->form->addElement('select','vn_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt1_1800','Saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','srt1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std1_1800','Standard deviation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','std1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv1_1800','Coefficient of variation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','cv1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt2_1800','Saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','srt2_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std2_1800','Standard deviation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','std2_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv2_1800','Coefficient of variation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','cv2_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqn_1800','Number of sequence Errors','');
		$this->form->addElement('select','eseqn_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqper_1800','Percent of sequence errors','');
		$this->form->addElement('select','eseqper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipn_1800','Number of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipn_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipper_1800','Percent of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopn_1800','Number of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopn_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopper_1800','Percent of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimen_1800','Number of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimen_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimeper_1800','Percent of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimeper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimen_1800','Number of timing errors','');
		$this->form->addElement('select','corretimen_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimeper_1800','Percent of timing errors','');
		$this->form->addElement('select','corretimeper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalsen_1800','Number of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalsen_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalseper_1800','Percent of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalseper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalsen_1800','Number of false starts only','');
		$this->form->addElement('select','correfalsen_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalseper_1800','Percent of false starts only','');
		$this->form->addElement('select','correfalseper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepn_1800','Number of trials with step saccades','');
		$this->form->addElement('select','stepn_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepper_1800','Percent of trials with step saccades','');
		$this->form->addElement('select','stepper_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel1_1800','Velocity of first saccade','');
		$this->form->addElement('select','vel1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp1_1800','Amplitude of the first saccade','');
		$this->form->addElement('select','amp1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel2_1800','Velocity of second saccade','');
		$this->form->addElement('select','vel2_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp2_1800','Amplitude of the second saccade','');
		$this->form->addElement('select','amp2_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','firstang_1800','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','firstang_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fsac_acc_1800','Accuracy of the first saccade','');
		$this->form->addElement('select','fsac_acc_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','acc_1800','Accuracy of the final fixation to the second target','');
		$this->form->addElement('select','acc_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_t1_1800','Accuracy of the closest fixation to T1(most useful)','');
		$this->form->addElement('select','fix_acc_t1_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_1800','Accuracy of the closest fixation to T2(most useful)','');
		$this->form->addElement('select','fix_acc_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','plength_acc_1800','Path length accuracy (actual/optimal path length)','');
		$this->form->addElement('select','plength_acc_1800_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
