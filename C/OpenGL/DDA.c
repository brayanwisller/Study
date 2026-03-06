#include<stdio.h>
#include<math.h>

void DDA(int x1, int y1, int x2, int y2){
	int k;
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;
	
	float m = (float) deltaY / deltaX;
	
	int passos = deltaX;
	
	if(deltaY > deltaX){
		passos = deltaY;
	}
	
	for(k = 0; k <= passos; k++){
		int x = x1 + k;
		int y = round(y1 + k * m);
		
		printf("X%d = %d, Y%d = %d\n", (k + 1), x, (k + 1), y);
	}	
}

int main(){
	int x1, x2, y1, y2;
	
	printf("Digite o X1 = ");
	scanf("%d", &x1);
	
	printf("Digite o Y1 = ");
	scanf("%d", &y1);
	
	printf("Digite o X2 = ");
	scanf("%d", &x2);
	
	printf("Digite o Y2 = ");
	scanf("%d", &y2);
	
	DDA(x1, y1, x2, y2);
}
