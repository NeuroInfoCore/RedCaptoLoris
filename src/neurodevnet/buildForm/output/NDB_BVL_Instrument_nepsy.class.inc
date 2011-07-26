<?php 
class NDB_BVL_Instrument_nepsy extends NDB_BVL_Instrument {

 
	function setup($commentID, $page){ 
		$this->formType="XIN"; 
		$this->form = new HTML_Quickform('test_form'); 

		$this->testName = "nepsy"; 
		$this->table = "nepsy"; 

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
		$this->form->addElement('text','ii_as_ttl_err_r','Animal sorting total errors raw score','');
		$this->form->addElement('select','ii_as_ttl_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_rs_err_r','Animal sorting total repeated sort errors raw score score','');
		$this->form->addElement('select','ii_as_ttl_rs_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_ns_err_r','Animal sorting total novel sort errors raw score','');
		$this->form->addElement('select','ii_as_ttl_ns_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_cor_s','Animal sorting total correct scaled score','');
		$this->form->addElement('select','ii_as_ttl_cor_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_comb_s','Animal sorting combined scaled score','');
		$this->form->addElement('select','ii_as_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_cor_p','Animal sorting total correct percentile rank','');
		$this->form->addElement('select','ii_as_ttl_cor_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_err_p','Animal sorting total errors percentile rank','');
		$this->form->addElement('select','ii_as_ttl_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_rs_err_p','Animal sorting total repeated sort percentile rank','');
		$this->form->addElement('select','ii_as_ttl_rs_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_ttl_ns_err_p','Animal sorting total novel sort error percentile rank','');
		$this->form->addElement('select','ii_as_ttl_ns_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_as_comb_p','Animal sorting combined scaled score percentile rank','');
		$this->form->addElement('select','ii_as_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_cor_r','Auditory attn. total correct raw score','');
		$this->form->addElement('select','ii_aa_ttl_cor_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_o_err_r','Auditory attn. total omission errors raw score','');
		$this->form->addElement('select','ii_aa_ttl_o_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_c_err_r','Auditory attn. total commission errors raw score','');
		$this->form->addElement('select','ii_aa_ttl_c_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_i_err_r','Auditory attn. total inhibitory errors raw score','');
		$this->form->addElement('select','ii_aa_ttl_i_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_corr_r','Response set total correct raw score','');
		$this->form->addElement('select','ii_rs_ttl_corr_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_o_err_r','Response set total omission errors raw score','');
		$this->form->addElement('select','ii_rs_ttl_o_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_c_err_r','Response set total commission errors raw score','');
		$this->form->addElement('select','ii_rs_ttl_c_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_i_err_r','Response set total inhibitory errors raw score','');
		$this->form->addElement('select','ii_rs_ttl_i_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_cor_s','Auditory attn. total correct scaled score','');
		$this->form->addElement('select','ii_aa_ttl_cor_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_comb_s','Auditory attn. combined scaled score','');
		$this->form->addElement('select','ii_aa_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_cor_s','Response set total correct scaled score','');
		$this->form->addElement('select','ii_rs_ttl_cor_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_comb_s','Response set combined scaled score','');
		$this->form->addElement('select','ii_rs_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_rs_cont_s','AA vs. RS contrast scaled score','');
		$this->form->addElement('select','ii_aa_rs_cont_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_cor_p','Auditory attn. total correct percentile rank','');
		$this->form->addElement('select','ii_aa_ttl_cor_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_comb_p','Auditory attn. combined scaled score percentile rank','');
		$this->form->addElement('select','ii_aa_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_o_err_p','Auditory attn. total omission error percentile rank','');
		$this->form->addElement('select','ii_aa_ttl_o_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_c_err_p','Auditory attn.total commission error percentile rank','');
		$this->form->addElement('select','ii_aa_ttl_c_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_ttl_i_err_p','Auditory attn. total inhibitory error percentile rank','');
		$this->form->addElement('select','ii_aa_ttl_i_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_cor_p','Response set total correct percentile rank','');
		$this->form->addElement('select','ii_rs_ttl_cor_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_comb_p','Response set combined scaled score percentile rank','');
		$this->form->addElement('select','ii_rs_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_o_err_p','Response set total omission error percentile rank','');
		$this->form->addElement('select','ii_rs_ttl_o_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_c_err_p','Response set total commission error percentile rank','');
		$this->form->addElement('select','ii_rs_ttl_c_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_rs_ttl_i_err_p','Response set total inhibitory error percentile rank','');
		$this->form->addElement('select','ii_rs_ttl_i_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_aa_rs_cont_p','AA vs. RS contrast scaled score percentile rank','');
		$this->form->addElement('select','ii_aa_rs_cont_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_t_r','Inhibition-naming completion time raw score','');
		$this->form->addElement('select','ii_in_n_t_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_err_r','Inhibition-naming total errors raw score','');
		$this->form->addElement('select','ii_in_n_ttl_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_sc_err_r','Inhibition-naming total self corrected errors raw score','');
		$this->form->addElement('select','ii_in_n_ttl_sc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_uc_err_r','Inhibition-naming total uncorrected errors raw score','');
		$this->form->addElement('select','ii_in_n_ttl_uc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_t_r','Inhibition-inhibition completion time raw score','');
		$this->form->addElement('select','ii_in_i_t_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_err_r','Inhibition-inhibition total errors raw score','');
		$this->form->addElement('select','ii_in_i_ttl_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_sc_err_r','Inhibition-inhibition total self corrected errors raw score','');
		$this->form->addElement('select','ii_in_i_ttl_sc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_uc_err_r','Inhibition-inhibition total uncorrected errors raw score','');
		$this->form->addElement('select','ii_in_i_ttl_uc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_n_s_t_r','Inhibition-switching completion time raw score','');
		$this->form->addElement('select','ii_n_s_t_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_err_r','Inhibition-switching total errors raw score','');
		$this->form->addElement('select','ii_in_s_ttl_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_sc_err_r','Inhibition-switching total self corrected errors raw score','');
		$this->form->addElement('select','ii_in_s_ttl_sc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_uc_err_r','Inhibition-switching total uncorrected errors raw score','');
		$this->form->addElement('select','ii_in_s_ttl_uc_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_ttl_err_r','Inhibition total errors raw score','');
		$this->form->addElement('select','ii_in_ttl_err_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_t_s','Inhibition-naming completion time scaled score','');
		$this->form->addElement('select','ii_in_n_t_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_comb_s','Inhibition-naming combined scaled score','');
		$this->form->addElement('select','ii_in_n_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_t_s','Inhibition-inhibition completion time scaled score','');
		$this->form->addElement('select','ii_in_i_t_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_comb_s','Inhibition-inhibition combined scaled score','');
		$this->form->addElement('select','ii_in_i_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_t_s','Inhibition-switching completion time scaled score','');
		$this->form->addElement('select','ii_in_s_t_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_comb_s','Inhibition-switching combined scaled score','');
		$this->form->addElement('select','ii_in_s_comb_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_ni_cont_s','Inhibition- Naming vs. Inhibition contrast scaled score','');
		$this->form->addElement('select','ii_in_ni_cont_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_is_cont_s','Inhibition- Inhibition vs. Switching Contrast scaled score','');
		$this->form->addElement('select','ii_in_is_cont_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_ttl_err_s','Inhibition total errors scaled score','');
		$this->form->addElement('select','ii_in_ttl_err_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_t_p','Inhibition-naming completion time percentile rank','');
		$this->form->addElement('select','ii_in_n_t_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_comb_p','Inhibition-naming combined scaled score percentile rank','');
		$this->form->addElement('select','ii_in_n_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_err_p','Inhibition-naming total errors percentile rank','');
		$this->form->addElement('select','ii_in_n_ttl_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_sc_err_p','Inhibition-naming total self corrected errors percentile rank','');
		$this->form->addElement('select','ii_in_n_ttl_sc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_n_ttl_uc_err_p','Inhibition-naming total uncorrected errors percentile rank','');
		$this->form->addElement('select','ii_in_n_ttl_uc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_t_p','Inhibition-inhibition completion time percentile rank','');
		$this->form->addElement('select','ii_in_i_t_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_comb_p','Inhibition-inhibition combined scaled score percentile rank','');
		$this->form->addElement('select','ii_in_i_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_err_p','Inhibition-inhibition total errors percentile rank','');
		$this->form->addElement('select','ii_in_i_ttl_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_sc_err_p','Inhibition-inhibition total self corrected errors percentile rank','');
		$this->form->addElement('select','ii_in_i_ttl_sc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_i_ttl_uc_err_p','Inhibition-inhibition total uncorrected errors percentile rank','');
		$this->form->addElement('select','ii_in_i_ttl_uc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_t_p','Inhibition-switching completion time percentile rank','');
		$this->form->addElement('select','ii_in_s_t_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_comb_p','Inhibition-switching combined scaled score percentile rank','');
		$this->form->addElement('select','ii_in_s_comb_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_err_p','Inhibition-switching total errors percentile rank','');
		$this->form->addElement('select','ii_in_s_ttl_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_sc_err_p','Inhibition-switching total self corrected errors percentile rank','');
		$this->form->addElement('select','ii_in_s_ttl_sc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_s_ttl_uc_err_p','Inhibition-switching total uncorrected errors percentile rank','');
		$this->form->addElement('select','ii_in_s_ttl_uc_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_ni_cont_p','Inhibition- naming vs. inhibition contrast scaled score percentile rank','');
		$this->form->addElement('select','ii_in_ni_cont_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_is_cont_p','Inhibition- inhibition vs. switching contrast scaled score percentile rank','');
		$this->form->addElement('select','ii_in_is_cont_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_in_ttl_err_p','Inhibition total errors percentile rank','');
		$this->form->addElement('select','ii_in_ttl_err_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_r','Memory for names total raw score','');
		$this->form->addElement('select','ii_mn_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mnd_r','Memory for names delayed total score raw score','');
		$this->form->addElement('select','ii_mnd_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_mnd_r','Memory for names and memory for names delayed total score raw score','');
		$this->form->addElement('select','ii_mn_mnd_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_s','Memory for names total scaled score','');
		$this->form->addElement('select','ii_mn_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mnd_s','Memory for names delayed total scaled score','');
		$this->form->addElement('select','ii_mnd_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_mnd_s','Memory for names and memory for names delayed total scaled score','');
		$this->form->addElement('select','ii_mn_mnd_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_p','Memory for names total percentile rank','');
		$this->form->addElement('select','ii_mn_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mnd_p','Memory for names delayed total percentile rank','');
		$this->form->addElement('select','ii_mnd_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_mn_mnd_p','Memory for names and memory for names delayed total percentile rank','');
		$this->form->addElement('select','ii_mn_mnd_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_ar_ttl_r','Arrows total score raw score','');
		$this->form->addElement('select','ii_ar_ttl_r_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_ar_ttl_s','Arrows total score scaled score','');
		$this->form->addElement('select','ii_ar_ttl_s_status','Status',array(null => '','not_answered' =>'Not Answered'));
		$this->form->addElement('text','ii_ar_ttl_p','Arrows total score percentile rank','');
		$this->form->addElement('select','ii_ar_ttl_p_status','Status',array(null => '','not_answered' =>'Not Answered'));
    } 
} 
?> 
