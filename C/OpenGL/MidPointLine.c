#include<stdio.h>
#include<math.h>
#include<locale.h>

void MidPointLine(int x1, int y1, int x2, int y2, int cor){
	int dx = x2 - x1;
	int dy = y2 - y1;
	int inc1 = 2 * dy;
	int inc2 = 2 * (dy + dx);
	int v = 2 * dy + dx;
	int x = x1;
	int y = y1;
	
	printf("(%d, %d)", x, y);
	
	while(x < x2){
		if(v <= 0){
			v += inc1;
		} else {
			v += inc2;
			++y;
		}
		++x;
		printf("(%d, %d)", x, y);
    }
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int x1, y1, x2, y2, cor;
	
	printf("Digite o valor de X1: ");
	scanf("%d", &x1);
	
	printf("Digite o valor de Y1: ");
	scanf("%d", &y1);
	
	printf("Digite o valor de X2: ");
	scanf("%d", &x2);
	
	printf("Digite o valor de Y2: ");
	scanf("%d", &y2);
	
	printf("O valor da cor é: ", cor);
	
	MidPointLine(x1, y1, x2, y2, cor);
}
