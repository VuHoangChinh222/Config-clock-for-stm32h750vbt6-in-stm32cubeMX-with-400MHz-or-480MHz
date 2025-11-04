#include<iostream>

using namespace std;

int main(){
	int choice;
	do{
		cout<<"Select maximum clock to configure for stm32h750vbt6: [1]:400MHz; [2]:480MHz\n";
		cout<<"Please select your choice: ";
		cin>>choice;
	}while(choice<1||choice>2);
	
	if(choice == 1){
		for(int i = 4; i<=48;i++){
			for(int j = 1;j<=63;j++){
				if(i/j<1 || i/j>16)
					continue;
				for(int z = 4;z<=512;z++){
					if(i/j*z<150 || i/j*z>960)
						continue;
					for(int a = 2; a<=128;a+=2){
						if(i/j*z/a== 400){
							for(int b =1;b<=128;b++){
								if(i/j*z/b==200)
									cout<<"HSE: "<<i<<", DIVM1: "<<j<<", DIVN1: "<<z<<", DIVP1: "<<a<<", DIVQ1: "<<b<<endl;
							}	
						}
					}
				}
			}	
		}	
	}else{
		for(int i = 4; i<=48;i++){
			for(int j = 1;j<=63;j++){
				if(i/j<1 || i/j>16)
					continue;
				for(int z = 4;z<=512;z++){
					if(i/j*z<150 || i/j*z>960)
						continue;
					for(int a = 2; a<=128;a+=2){
						if(i/j*z/a== 480){
							cout<<"HSE: "<<i<<", DIVM1: "<<j<<", DIVN1: "<<z<<", DIVP1: "<<a<<endl;	
						}
					}
				}
			}
		}	
	}
	return  0;
}
