// Truth Plots for MC Validation

// Header          

#ifndef MyAnalysis_TruthPlots_H
#define MyAnalysis_TruthPlots_H

#include <AnaAlgorithm/AnaAlgorithm.h>
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
//#include <TTree.h>             

#include <vector>
#include <JetInterface/IJetSelector.h>
#include <EventLoop/Worker.h>

// GRL                           

#include <AsgAnalysisInterfaces/IGoodRunsListSelectionTool.h>
#include <AsgTools/AnaToolHandle.h>

// include files for using the trigger tools

#include <TrigConfInterfaces/ITrigConfigTool.h>
#include <TrigDecisionTool/TrigDecisionTool.h>

// For systematics                          

#include <SystematicsHandles/SysReadHandle.h>
#include <SystematicsHandles/SysListHandle.h>

// Jet Calibration Tools                    

#include <JetCalibTools/IJetCalibrationTool.h>

// JER                                       

#include <JetResolution/IJERTool.h>

class TruthPlots : public EL::AnaAlgorithm
{
 public:
  // this is a standard algorithm constructor 
  TruthPlots (const std::string& name, ISvcLocator* pSvcLocator);

  // these are the functions inherited from Algorithm
  //  virtual StatusCode beginInputFile () override;
  //  virtual StatusCode changeInput (bool firstFile);
  virtual StatusCode initialize () override;
  virtual StatusCode execute () override;
  virtual StatusCode finalize () override;
  //  ~Project1 () override;                                                                                 
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain                                     
  //Int_t           fCurrent; //!current Tree number in a TChain

  // I don't think we can have the following because of the period
  //std::vector<float> *TruthPhotonsAuxDyn.m = nullptr;  so we'll try
  /*
  std::vector<float> *m = nullptr; 
  std::vector<float> *px = nullptr;
  std::vector<float> *py = nullptr;
  std::vector<float> *pz = nullptr;
  std::vector<float> *e = nullptr;
  */

  std::vector<float> *ph_E = nullptr;
  std::vector<float> *ph_pt = nullptr;
  std::vector<float> *ph_phi = nullptr;
  std::vector<float> *ph_eta = nullptr;

  std::vector<float> *jet_E = nullptr;
  std::vector<float> *jet_pt = nullptr;
  std::vector<float> *jet_phi = nullptr;
  std::vector<float> *jet_eta = nullptr;

  std::vector<float> *fatjet_m = nullptr;
  std::vector<float> *fatjet_pt = nullptr;
  std::vector<float> *fatjet_phi = nullptr;
  std::vector<float> *fatjet_eta = nullptr;

  float_t Zprime_pt;
  float_t Zprime_eta;
  float_t Zprime_phi;
  float_t Zprime_m;
  float_t weight;
 
  /*
  Float_t Zprime_pt;
  Float_t Zprime_eta;
  Float_t Zprime_phi;
  Float_t Zprime_m;
  Float_t weight;
  */

  //Float_t weight;

  /*
  Float_t m;
  Float_t px;
  Float_t py;
  Float_t pz;
  Float_t e;
  */

  /*
  std::vector<float> *m = nullptr;
  std::vector<float> *px = nullptr;
  std::vector<float> *py = nullptr;
  std::vector<float> *pz = nullptr;
  std::vector<float> *e = nullptr;
  */

  //std::vector<float> *Zprime_pt = nullptr;

 private:
  // Configuration, and any other types of variables go here.


  //  double Zprime_pt;

  /*                                                                                                           
  TString jetAlgo = "AntiKt10LCTopoTrimmedPtFrac5SmallR20"; // Jet collection, for example AntiKt4EMTopo
  TString config = "JES_MC16recommendation_FatJet_Trimmed_JMS_comb_170ct2018.config"; // Global config
  TString calibSeq = "EtaJES_JMS";
// Calibration sequence to apply
     TString calibArea = "00-04-82"; // Calibration Area tag
     bool isData = false; // Bool describing if the events are data or from simulation
  */

  // Jet Calibration Tools 

  //asg::AnaToolHandle<IJetCalibrationTool> JetCalibrationTool_handle;

  // JER                   

  //asg::AnaToolHandle<IJERTool> JER_handle;


};

#endif
