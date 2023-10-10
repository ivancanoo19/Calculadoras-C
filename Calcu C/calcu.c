#include <stdio.h>

float res=0;

void suma(float a, float b);
void resta(float a, float b);
void mult(float a, float b);
void div(float a, float b);

void suma(float a, float b){
	res = a+b;
	printf("\nSuma: %.3f\n", res);
}

void resta(float a, float b){
	res = a-b;
	printf("\nResta: %.3f\n", res);
}

void mult(float a, float b){
	res = a*b;
	printf("\nMultiplicacion: %.3f\n", res);
}

void div(float a, float b){
	if(b == 0){
		printf("\nError, el divisor no puede ser cero\n");
		return;
	}
	res = a/b;
	printf("\nDivison: %.3f\n", res);
}


int main(){
	int op;
	float num1=0, num2=0;
	
	do{
		printf("\n----CALCULADORA----");
		printf("\n1) Ingresar dos nuevos numeros");
		printf("\n2) Sumar");
		printf("\n3) Restar");
		printf("\n4) Muliplicar");
		printf("\n5) Dividir");
		printf("\n6) Salir");
		
		printf("\nOpcion: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\n- Ingresa el primer numero: ");
				scanf("%f", &num1);
				
				printf("\n- Ingresa el primer numero: ");
				scanf("%f", &num2);
				break;
				
			case 2:
				suma(num1, num2);
				break;
				
			case 3:
				resta(num1, num2);
				break;
				
			case 4:
				mult(num1, num2);
				break;
				
			case 5:
				div(num1, num2);
				break;
				
			case 6: 
				printf("\n\nSaliendo...");
				break;
				
			default: 
				printf("\n-Opcion no valida, intente de nuevo\n");
				break;
		}
		
	}while(op != 6);
	
	return 0;
}
