#include "TMath.h"
#include "TFile.h"
#include "TTree.h"
#include "TLatex.h"
#include "TAttAxis.h"
#include "TGraph.h"

void Anu_diffxs_sf()


{
//plot theory cross section
TGraph *g1 = new TGraph("nucl_th_sf/xsec_dsigma_diff_Anu_1g_15_sf_NC_reduced.out");

g1->Draw("AL");

g1->GetXaxis()->SetLimits(0.0,600.0);
g1->GetYaxis()->SetRangeUser(0.0,15.0);
g1->GetXaxis()->SetTitle("#omega [MeV]");
g1->GetXaxis()->SetTitleSize(.075);
g1->GetXaxis()->SetLabelSize(.075);
g1->GetYaxis()->SetTitle("d#sigma/d#Omegad#omega (10^{-15} fm^{2}/sr/MeV)");
g1->GetYaxis()->SetTitleOffset(1.4);
g1->GetYaxis()->SetTitleSize(.075);
g1->GetYaxis()->SetLabelSize(.075);
g1->SetTitle("");

g1->SetLineColor(1);
g1->SetLineWidth(3);
g1->SetLineStyle(2);

gStyle->SetOptStat(0);

TFile* f1 = TFile::Open("neut-Anu-sf.root");
TTree* tree1 = (TTree*)f1->Get("FlatTree_VARS");


leg = new TLegend(0.60,0.65,0.95,0.995);



//Histogram with cuts on theta, energy
//fScaleFactor_alttest to get units of cm^2
//10e41 so the axis is in 10e-15 fm^2
//Divide by 2*pi*d(cos(theta)) and d(omega)= 20. MeV
tree1->Draw("1000*q0>>h1(30,0,600)","10e41*fScaleFactor_alttest/(20.*2.*TMath::Pi()*(TMath::Cos(12.5*TMath::Pi()/180.)-TMath::Cos(17.5*TMath::Pi()/180.)))*( (TMath::Abs(Mode)>50)&&(TMath::Abs(TMath::ACos(CosLep)/TMath::Pi()*180. - 15.)< 2.5) &&(TMath::Abs(Enu_true-1.0) < 0.01))","EHIST && same");
h1->Scale(15.);//truth cut in energy


gPad->SetLeftMargin(0.2);
gPad->SetBottomMargin(0.2);
gPad->SetRightMargin(0.15);
gPad->Update();

h1->SetLineColor(kBlue);
h1->SetLineWidth(3);



leg->AddEntry(g1,"SF","l");
leg->AddEntry(h1,"N-SF","l");
leg->Draw("same");

leg->SetTextSize(0.065);
leg->SetFillColor(0);

TPad *newpad = new TPad("newpad","",0,0,1,1);
newpad->SetFillStyle(4000);
newpad->Draw();
newpad->cd();

TPaveLabel *tpl = new TPaveLabel(0.63,0.46,0.83,0.61,"#theta = 15^{#circ}");
tpl->SetBorderSize(0);
tpl->SetTextSize(0.75);
tpl->SetFillColor(0);
tpl->Draw();

newpad->SaveAs("./diffxs_1g_15_Anu_sf.png");

}


