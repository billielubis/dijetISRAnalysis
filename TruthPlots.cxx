// Truth Plots for MC Validation

// Source Code                                                                                                

#include <AsgTools/MessageCheck.h>
#include <MyAnalysis/TruthPlots.h>
#include <xAODEventInfo/EventInfo.h>
#include <xAODJet/JetContainer.h>
#include <TSystem.h>
#include <PATInterfaces/CorrectionCode.h> // to check the return correction code status of tools
#include <TMath.h>

#include <TApplication.h>
#include <vector>
#include <AsgTools/AsgMetadataTool.h>
#include <xAODCore/ShallowAuxContainer.h>
#include <xAODCore/ShallowCopy.h>
#include <xAODCore/AuxContainerBase.h>
#include <JetCalibTools/IJetCalibrationTool.h>

TruthPlots :: TruthPlots (const std::string& name,
			      ISvcLocator *pSvcLocator)
: EL::AnaAlgorithm (name, pSvcLocator)
//m_grl ("GoodRunsListSelectionTool/grl", this),                                                             
//m_jetCleaning ("JetCleaningTool/JetCleaning", this),                                                       
//m_JERTool ("JERTool", this),                                                                               
//JetCalibrationTool_handle ("JetCalibrationTool", this)                                                      

{

  // Here you put any code for the base initialization of variables,                                           
  // e.g. initialize all pointers to 0.  This is also where you                                                
  // declare all properties for your algorithm.  Note that things like                                         
  // resetting statistics variables or booking histograms should                                               
  // rather go into the initialize() function.                                                                 
  // declare the tool handle as a property on the algorithm                                                    

  //m_grl.declarePropertyFor (this, "grlTool");                                                               


}

StatusCode TruthPlots :: initialize ()
{
  // Here you do everything that needs to be done at the very                                                  
  // beginning on each worker node, e.g. create histograms and output                                          
  // trees.  This method gets called before any input files are                                                
  // connected.                                                                                                

  ANA_MSG_INFO ("in initialize");

  /*
  ANA_CHECK (book (TH1F ("h_truth_pt", "h_truth_pt", 100, 0, 1000)));
  ANA_CHECK (book (TH1F ("h_truth_eta", "h_truth_eta", 100, -4, 4)));
  ANA_CHECK (book (TH1F ("h_truth_phi_x", "h_truth_phi_x", 100, -3.5, 3.5)));
  ANA_CHECK (book (TH1F ("h_truth_phi_y", "h_truth_phi_y", 100, -3.5, 3.5)));
  ANA_CHECK (book (TH1F ("h_truth_m", "h_truth_m", 300, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_truth_m_calc", "h_truth_m_calc", 300, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_truth_e", "h_truth_e", 100, 0, 1000))); 
 //ANA_CHECK (book (TH1F ("h_weight", "h_weight", 50, -1, 2)));
  ANA_CHECK (book (TH1F ("h_truth_vpt", "h_truth_vpt", 100, 0, 1000)));
  ANA_CHECK (book (TH1F ("h_truth_veta", "h_truth_veta", 100, -4, 4)));
  ANA_CHECK (book (TH1F ("h_truth_vphi", "h_truth_vphi", 100, -3.5, 3.5))); 
  */

  ANA_CHECK (book (TH1F ("h_ph_E", "h_ph_E", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_ph_pt", "h_ph_pt", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_ph_eta", "h_ph_eta", 100, -5, 5)));
  ANA_CHECK (book (TH1F ("h_ph_phi", "h_ph_phi", 100, -4, 4)));

  ANA_CHECK (book (TH1F ("h_Zprime_pt", "h_Zprime_pt", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_Zprime_eta", "h_Zprime_eta", 100, -5, 5)));
  ANA_CHECK (book (TH1F ("h_Zprime_phi", "h_Zprime_phi", 100, -4, 4)));
  ANA_CHECK (book (TH1F ("h_Zprime_m", "h_Zprime_m", 200, 0, 1200)));

  ANA_CHECK (book (TH1F ("h_jet_E", "h_jet_E", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_jet_pt", "h_jet_pt", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_jet_eta", "h_jet_eta", 100, -5, 5)));
  ANA_CHECK (book (TH1F("h_jet_phi", "h_jet_phi", 100, -4, 4)));

  ANA_CHECK (book (TH1F ("h_fatjet_m", "h_fatjet_m", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_fatjet_pt", "h_fatjet_pt", 200, 0, 1200)));
  ANA_CHECK (book (TH1F ("h_fatjet_eta", "h_fatjet_eta", 100, -5, 5)));
  ANA_CHECK (book (TH1F("h_fatjet_phi", "h_fatjet_phi", 100, -4, 4)));

  return StatusCode::SUCCESS;


}


StatusCode TruthPlots :: execute ()
{
  // Here you do everything that needs to be done on every single                                             
  // events, e.g. read input variables, apply cuts, and fill                                                  
  // histograms and trees.  This is where most of your actual analysis                                        
  // code will go.                                                                                            

  ANA_MSG_INFO ("in execute");


  /*
  if (fChain == 0) return 0;

  //Long64_t nentries = 10;                                                                                    \

  Long64_t nentries = fChain->GetEntriesFast();

  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = fChain->LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    // if (Cut(ientry) < 0) continue;
    */


  fChain = wk()->tree();


  //fChain->SetBranchAddress("Zprime_pt", &Zprime_pt);
  //fChain->SetBranchAddress("Zprime_eta", &Zprime_eta);
  //fChain->SetBranchAddress("Zprime_phi", &Zprime_phi);
  //fChain->SetBranchAddress("Zprime_m", &Zprime_m);
  //fChain->SetBranchAddress("weight", &weight);

  /*
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.m", &m);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.px", &px);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.py", &py);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.pz", &pz);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.e", &e);
  */

  /*
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.px", &px);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.py", &py);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.pz", &pz);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.e", &e);
  fChain->SetBranchAddress("TruthPhotonsAuxDyn.m", &m);
  */

  fChain->SetBranchAddress("ph_E", &ph_E);
  fChain->SetBranchAddress("ph_pt", &ph_pt);
  fChain->SetBranchAddress("ph_eta", &ph_eta);
  fChain->SetBranchAddress("ph_phi", &ph_phi);

  fChain->SetBranchAddress("Zprime_pt", &Zprime_pt);                                                           
  fChain->SetBranchAddress("Zprime_eta", &Zprime_eta);                                                        
  fChain->SetBranchAddress("Zprime_phi", &Zprime_phi);                                                        
  fChain->SetBranchAddress("Zprime_m", &Zprime_m);
  fChain->SetBranchAddress("weight", &weight); 

  fChain->SetBranchAddress("jet_E", &jet_E);
  fChain->SetBranchAddress("jet_pt", &jet_pt);
  fChain->SetBranchAddress("jet_eta", &jet_eta);
  fChain->SetBranchAddress("jet_phi", &jet_phi);

  fChain->SetBranchAddress("fatjet_m", &fatjet_m);
  fChain->SetBranchAddress("fatjet_pt", &fatjet_pt);
  fChain->SetBranchAddress("fatjet_eta", &fatjet_eta);
  fChain->SetBranchAddress("fatjet_phi", &fatjet_phi);


  // PROBLEM LINE
  wk()->tree()->GetEntry (wk()->treeEntry());
  // PROBLEM LINE

  
  //TLorentzVector v1;
  //v1.SetPxPyPzE(px->at(0),py->at(0),pz->at(0),e->at(0)); 


  /*
  hist ("h_truth_pt")->Fill (sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))/1000); 
  hist ("h_truth_eta")->Fill (TMath::ASinH(pz->at(0)/sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))));
  hist ("h_truth_phi_x")->Fill (TMath::ACos(px->at(0)/sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))));
  hist ("h_truth_phi_y")->Fill (TMath::ASin(py->at(0)/sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))));
  hist ("h_truth_m")->Fill (m->at(0)); 
  hist ("h_truth_m_calc")->Fill ((e->at(0)*e->at(0)-(px->at(0)*px->at(0)+py->at(0)*py->at(0)+pz->at(0)*pz->at(0)))/1000);
  hist ("h_truth_e")->Fill (e->at(0)/1000); 
  hist ("h_truth_vpt")->Fill (v1.Pt());
  hist ("h_truth_veta")->Fill (v1.Eta());
  hist ("h_truth_vphi")->Fill (v1.Phi());
  */

  hist ("h_ph_pt")->Fill (ph_pt->at(0));
  hist ("h_ph_eta")->Fill (ph_eta->at(0));
  hist ("h_ph_phi")->Fill (ph_phi->at(0));
  hist ("h_ph_E")->Fill (ph_E->at(0));

  hist ("h_Zprime_pt")->Fill (Zprime_pt);
  hist ("h_Zprime_eta")->Fill (Zprime_eta);
  hist ("h_Zprime_phi")->Fill (Zprime_phi);
  hist ("h_Zprime_m")->Fill (Zprime_m);

  /*
  hist ("h_jet_E")->Fill (jet_E->at(0));
  hist ("h_jet_pt")->Fill (jet_pt->at(0));
  hist ("h_jet_phi")->Fill (jet_phi->at(0));
  hist ("h_jet_eta")->Fill (jet_eta->at(0));

  hist ("h_fatjet_m")->Fill (fatjet_m->at(0));
  hist ("h_fatjet_eta")->Fill (fatjet_eta->at(0));
  hist ("h_fatjet_phi")->Fill (fatjet_phi->at(0));
  hist ("h_fatjet_pt")->Fill (fatjet_pt->at(0));
  */

  // For if I need some sort of a loop
  /*
  //for (int i = 0; i < px->size(); i++)
  //for (int i = 0; i < px->size(); i++)
  //{
      hist ("h_truth_pt")->Fill (sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0)));
      hist ("h_truth_eta")->Fill (TMath::ASinH(pz->at(0)/sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))));
      hist ("h_truth_phi")->Fill (TMath::ACos(px->at(0)/sqrt(px->at(0)*px->at(0)+py->at(0)*py->at(0))));
      hist ("h_truth_m")->Fill (m->at(0));
      //}
      */

  


  // For if things should be formatted just like the reconstructed format
  /*
  hist ("h_truth_pt")->Fill (sqrt(px*px+py*py));
  hist ("h_truth_eta")->Fill (TMath::ASinH(pz/sqrt(px*px+py*py)));
  hist ("h_truth_phi")->Fill (TMath::ACos(px/sqrt(px*px+py*py)));
  hist ("h_truth_m")->Fill (m);
  */

  // Here's the reconstructed stuff for an example
  /*
  hist ("h_truth_pt")->Fill (Zprime_pt,weight);
  hist ("h_truth_eta")->Fill (Zprime_eta,weight);
  hist ("h_Zprime_phi")->Fill (Zprime_phi,weight);
  hist ("h_Zprime_m")->Fill (Zprime_m,weight);
  hist ("h_weight")->Fill (weight);
  */

  //}


  return StatusCode::SUCCESS;
}

StatusCode TruthPlots :: finalize ()
{
  // This method is the mirror image of initialize(), meaning it gets                                         
  // called after the last event has been processed on the worker node                                        
  // and allows you to finish up any objects you created in                                                   
  // initialize() before they are written to disk.  This is actually                                          
  // fairly rare, since this happens separately for each worker node.                                         
  // Most of the time you want to do your post-processing on the                                              
  // submission node after all your histogram outputs have been                                               
  // merged.                                                                                                  

  ANA_MSG_INFO ("in finalize");


  return StatusCode::SUCCESS;
}

/*                                                                                                            

Project1 :: ~Project1 ()                                                                                      

{                                                                                                             

  // Deconstructor stuff                                                                                      

delete tvar_jet_AntiKt10OrigLCTopoTrimmedPtFrac5SmallR20_pt;                                                  

                                                                                                              

}                                                                                                             
*/
