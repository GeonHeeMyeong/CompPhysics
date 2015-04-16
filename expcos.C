double factorial(int n) {
	
	if (n<=0) return 1;
	double x = 1;
	int b = 0;
	do {
		b++;
		x *= b;
	} while ( b != n);
	
	return x;
}

double exp(double *x, double *par) {
	
	double sum = 1;
	int n = par[0];
	
	for(int i = 1; i <= n; i++) {
		sum += pow(x[0], i)/factorial(i);
	}
	sum = sum;
	return sum;
}	

double cossum(double *x, double *par) {
	
	double sum = 1;
	int n = par[0];
	
	if(n==0) return sum;
	for(int i = 1; i <= n; i++) {
		sum += (pow(-1, i) * pow(x[0], 2*i))/factorial(2*i);
	}
	
	return sum;
}

double expcos(double *x, double *par) {
	
	double sum = 1;
	int n = par[0];
	
	double expsum = 1;
	double cossum = 1;
		
	for(int i = 1; i <= n; i++) {
		expsum = expsum + pow(x[0], i)/factorial(i);
	}
	
	for(int i = 1; i <= n; i++) {
		cossum = cossum + (pow(-1, i) * pow(x[0], 2*i))/factorial(2*i);
	}
	
	sum = expsum * cossum;
	return sum;
}

void expcos() {
	
	int number = 0;
	cout << "What is n for the function?" << endl;
	cin >> number;
	
	TCanvas *c1 = new TCanvas("c1","c1",800,800);
	gStyle->SetOptStat(0);
   
	TF1 *expcos = new TF1("exp_cos", expcos, 0, 33, 1);
	TF1 *exp = new TF1("exp", exp, 0, 33, 1);
	TF1 *cos = new TF1("cos", cos, 0, 33, 1);
	TF1 *real = new TF1("real", "exp(x)*cos(x)", 0, 33);
	
	expcos -> SetParameter(0, number);
	exp -> SetParameter(0, number);
	cos -> SetParameter(0, number);
	
	real -> SetLineColor(kBlack);
	real -> SetLineStyle(2);
	expcos -> SetLineColor(kRed);
	expcos -> SetLineStyle(1);
	exp -> SetLineColor(kBlue);
	exp -> SetLineStyle(2);
	cos -> SetLineColor(kGreen);
	cos -> SetLineStyle(2);
	
	expcos -> Draw();
	real -> DrawClone("Same");
	exp -> DrawClone("Same");
	cos -> DrawClone("Same");
	
	leg = new TLegend(0.8,0.9,1,1);
	leg->SetHeader("EXP*COS");
	leg->AddEntry("exp_cos","Exp*Cos Graph","l");
	leg->AddEntry("real","real Graph", "l");
	leg->AddEntry("exp","Exp Graph","l");
	leg->AddEntry("cos","Cos Graph","l");
	leg->Draw();
	
	c1->Print("expx*cosx n=**.pdf");
}
