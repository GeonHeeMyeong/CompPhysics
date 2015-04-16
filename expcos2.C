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
	
	if(n==0) return sum;
	for(int i = 1; i <= n; i++) {
		sum += sum + pow(x[0], i)/factorial(i);
	}
	
	return sum;
}	

double cos(double *x, double *par) {
	
	double sum = 1;
	int n = par[0];
	
	if(n==0) return sum;
	for(int i = 1; i <= n; i++) {
		sum = sum + (pow(-1, i) * pow(x[0], 2*i))/factorial(2*i);
	}
	
	return sum;
}

double expcos(double *x, double *par) {
	
	double const PI = 4*atan(1.);
	
	double sum = 1;
	double temp = 1;
	int n = par[0];
	
	
	if (n == 0) return sum;
	for(int i = 1; i <= n; i++) {
		
		if ( temp == 0) {
			temp = pow(x[0], i)*pow(2, i*0.5)*cos(i*PI/4)/factorial(2*i);
		}
		
		else if (i == 1 ) {
			sum += x[0];
		}
		
		sum += pow(x[0], i)*pow(2, i*0.5)*cos(i*PI/4)/factorial(i);
		
	}
	return sum;
}

void expcos2() {
	
	int number = 0;
	cout << "What is n for the function?" << endl;
	cin >> number;
	
	TCanvas *c1 = new TCanvas("c1","c1",800,800);
	gStyle->SetOptStat(0);
   
	TF1 *expcos = new TF1("exp_cos", expcos, 0, 33, 1);
	expcos -> SetParameter(0, number);
	expcos -> SetLineColor(kRed);
	expcos -> SetLineStyle(1);
	expcos -> DrawClone();
	
	TF1 *real = new TF1("real", "exp(x)*cos(x)", 0, 33); 
	
	real -> SetLineColor(kBlack);
	real -> SetLineStyle(2);
	real -> DrawClone("Same");
	
	TF1 *exp = new TF1("exp", exp, 0, 33, 1);
	exp -> SetParameter(0, number);
	exp -> SetLineColor(kBlue);
	exp -> SetLineStyle(2);
	exp -> DrawClone("Same");
	
	TF1 *cos = new TF1("cos", cos, 0, 33, 1);
	cos -> SetParameter(0, number);
	cos -> SetLineColor(kGreen);
	cos -> SetLineStyle(2);
	cos -> DrawClone("Same");
	
	leg = new TLegend(0.8,0.9,1,1);
	leg->SetHeader("EXP*COS");
	leg->AddEntry("exp_cos","Exp*Cos Graph","l");
	leg->AddEntry("real","real Graph", "l");
	leg->AddEntry("exp","Exp Graph","l");
	leg->AddEntry("cos","Cos Graph","l");
	leg->Draw();
	
	c1->Print("expx*cosx n=15.pdf");
	
}
