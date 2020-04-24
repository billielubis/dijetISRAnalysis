#include <AsgTools/MsgLevel.h>

void ATestRun_eljob (const std::string& submitDir)
{
  // Set up the job for xAOD access:
  xAOD::Init().ignore();

  // create a new sample handler to describe the data files we use
  SH::SampleHandler sh;

  // scan for datasets in the given directory
  // this works if you are on lxplus, otherwise you'd want to copy over files
  // to your local machine and use a local path.  if you do so, make sure
  // that you copy all subdirectories and point this to the directory
  // containing all the files, not the subdirectories.

  /*
  // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file:
  const char* inputFilePath = gSystem->ExpandPathName ("/eos/user/c/cdelitzs/Wprime/mc16_13TeV.426347.Pythia8EvtGen_A14NNPDF23LO_WprimeWZ_flatpT.deriv.DAOD_JETM6.e6880_s3126_r10201_p3712/");
  SH::ScanDir().filePattern("DAOD_JETM6.16462690._000119.pool.root.1").scan(sh,inputFilePath);
  */

  //SH::readFileList(sh, "myTestFile", "filelist.txt");
  
  //SH::readFileList(sh, "myTestFile", "massfiles.txt"); // for Z' samples
  SH::readFileList(sh, "myTestFile", "truthfiles.txt"); // for truth Samples
  
  // set the name of the tree in our files
  // in the xAOD the TTree containing the EDM containers is "CollectionTree"
  // actually for the z' samples it's in TreeDirectory/JetTree
  sh.setMetaString ("nc_tree", "outTree"); // use for reco Z' samples
  //sh.setMetaString ("nc_tree", "CollectionTree"); // use for truth samples

  // further sample handler configuration may go here

  // print out the samples we found
  sh.print ();

  // this is the basic description of our job
  EL::Job job;
  job.sampleHandler (sh); // use SampleHandler in this job
  //job.options()->setDouble (EL::Job::optMaxEvents, 500); // for testing purposes, limit to run over the first 500 events only!

  // Add an output stream called "ANALYSIS".
  //  job.outputAdd( EL::OutputStream( "ANALYSIS" ) );


  // add our algorithm to the job
  EL::AnaAlgorithmConfig alg;
  //alg.setType ("MCValidation");
  alg.setType ("TruthPlots");

  // set the name of the algorithm (this is the name use with
  // messages)
  alg.setName ("AnalysisAlg");
  alg.setUseXAODs (false); 
  // later on we'll add some configuration options for our algorithm that go here
  //alg.setProperty( "ElectronPtCut", 30000.0 ).ignore();
  //alg.setProperty( "SampleName", "Zee" ).ignore();
  //  alg.setProperty( "outputStreamName", "OStream").ignore();
  //  alg.setProperty ("OutputLevel", MSG::DEBUG);


  job.algsAdd (alg);
  

  // make the driver we want to use:
  // this one works by running the algorithm directly:
  EL::DirectDriver driver;
  // we can use other drivers to run things on the Grid, with PROOF, etc.

  // process the job using the driver
  driver.submit (job, submitDir);
}
