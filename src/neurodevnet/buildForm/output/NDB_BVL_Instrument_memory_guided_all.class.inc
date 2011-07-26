<?php 
class NDB_BVL_Instrument_memory_guided_all extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "memory_guided_all"; 
		$this->table = "memory_guided_all"; 

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
		$this->form->addElement('text','vn_all','Number of viable trials','');
		$this->form->addElement('select','vn_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt1_all','Saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','srt1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std1_all','Standard deviation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','std1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv1_all','Coefficient of variation of saccadic reaction time of first saccade of correct trials','');
		$this->form->addElement('select','cv1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','srt2_all','Saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','srt2_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','std2_all','Standard deviation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','std2_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','cv2_all','Coefficient of variation of saccadic reaction time of second saccade of correct trials','');
		$this->form->addElement('select','cv2_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqn_all','Number of sequence Errors','');
		$this->form->addElement('select','eseqn_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqper_all','Percent of sequence errors','');
		$this->form->addElement('select','eseqper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipn_all','Number of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipn_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eskipper_all','Percent of trials where they skipped the first target and go to second only','');
		$this->form->addElement('select','eskipper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopn_all','Number of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopn_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','estopper_all','Percent of trials where they went to the first target only and stopped','');
		$this->form->addElement('select','estopper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimen_all','Number of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimen_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqetimeper_all','Percent of trials that are sequence and timing errors','');
		$this->form->addElement('select','eseqetimeper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimen_all','Number of timing errors','');
		$this->form->addElement('select','corretimen_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','corretimeper_all','Percent of timing errors','');
		$this->form->addElement('select','corretimeper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalsen_all','Number of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalsen_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','eseqefalseper_all','Percent of false starts with sequence errors','');
		$this->form->addElement('select','eseqefalseper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalsen_all','Number of false starts only','');
		$this->form->addElement('select','correfalsen_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','correfalseper_all','Percent of false starts only','');
		$this->form->addElement('select','correfalseper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepn_all','Number of trials with step saccades','');
		$this->form->addElement('select','stepn_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','stepper_all','Percent of trials with step saccades','');
		$this->form->addElement('select','stepper_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel1_all','Velocity of first saccade','');
		$this->form->addElement('select','vel1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp1_all','Amplitude of the first saccade','');
		$this->form->addElement('select','amp1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','vel2_all','Velocity of second saccade','');
		$this->form->addElement('select','vel2_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','amp2_all','Amplitude of the second saccade','');
		$this->form->addElement('select','amp2_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','firstang_all','Angle between direct path to target and first saccade','');
		$this->form->addElement('select','firstang_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fsac_acc_all','Accuracy of the first saccade','');
		$this->form->addElement('select','fsac_acc_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','acc_all','Accuracy of the final fixation to the second target','');
		$this->form->addElement('select','acc_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_t1_all','Accuracy of the closest fixation to T1(most useful)','');
		$this->form->addElement('select','fix_acc_t1_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','fix_acc_all','Accuracy of the closest fixation to T2(most useful)','');
		$this->form->addElement('select','fix_acc_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','plength_acc_all','Path length accuracy (actual/optimal path length)','');
		$this->form->addElement('select','plength_acc_all_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
