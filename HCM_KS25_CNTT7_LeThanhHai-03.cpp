#include <stdio.h>
#define MAX_SIZE 50

int main(void){
	int passengers[MAX_SIZE] = {32,18,45,27,50};
	int n=5;
	int value;
	int pos;
	int choice;
	int count;
	int target;
	
	while(1){
		printf("===============================================\n");
		printf("  CHUONG TRINH QUAN LY HANH KHACH CITYBUS\n");
		printf("===============================================\n");
		printf("1. Them so hanh khach\n");
		printf("2. Sua so hanh khach\n");
		printf("3. Xoa so hanh khach\n");
		printf("4. Tim kiem so hanh khach\n");
		printf("0. Thoat chuong trinh\n");
		printf("===============================================\n");
		
		printf("Vui long nhap lua chon cua ban (0 - 4): ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				if(n == MAX_SIZE){
					printf("Mang da day, khong the them!");
					break;
				}
				
				printf("Mang ban dau \n");
				for(int i=0; i < n;i++){
					printf("%d ", passengers[i]);
				}
				printf("\n");
				
				printf("Nhap so luong hanh khach muon them: ");
				scanf("%d", &value);
				
				if(value < 0){
					printf("So luong muon them khong hop le!\n");
					break;
				}
				
				printf("Nhap vi tri muon them: ");
				scanf("%d", &pos);
				
				if(pos < 1 || pos > n+1){
					printf("Vi tri chen khong hop le!");
					break;
				}
				
				for(int i = n; i >= pos; i--){
					passengers[i] = passengers[i-1];
				}
				passengers[pos-1] = value;
				n++;
				
				printf("Mang sau khi them\n");
				for(int i=0; i < n;i++){
					printf("%d ", passengers[i]);
				}
				printf("\n");
				break;
			case 2:
				printf("Nhap vi tri muon sua: ");
				scanf("%d", &pos);
				
				if(pos < 1 || pos > n){
					printf("Vi tri sua khong hop le!");
					break;
				}
				
				printf("Nhap so luong hanh khach moi: ");
				scanf("%d", &value);
				
				if(value < 0){
					printf("So hanh khach khong hop le!\n");
					break;
				}
				
				passengers[pos-1] = value;
				
				printf("Mang sau khi sua\n");
				for(int i=0; i < n;i++){
					printf("%d ", passengers[i]);
				}
				printf("\n");
				break;
			case 3:
				if(n == 0){
					printf("Mang rong, khong the xoa!");
					break;
				}
				
				printf("Nhap vi tri muon xoa: ");
				scanf("%d", &pos);
				
				if(pos < 1 || pos > n){
					printf("Vi tri xoa khong hop le!");
					break;
				}
				
				for(int i = pos - 1; i < n-1; i++){
					passengers[i] = passengers[i-1];
				}
				passengers[pos-1] = value;
				n--;
				
				printf("Mang sau khi xoa\n");
				for(int i=0; i < n;i++){
					printf("%d ", passengers[i]);
				}
				printf("\n");
				break;
			case 4:
				printf("Nhap so luong hanh khach muon tim: ");
				if(scanf("%d", &target) !=1){
					printf("Du lieu khong hop le!\n");
					break;
				}
				if(target < 0){
					printf("Du lieu tim kiem khong hop le!\n");
					break;
				}
				count = 0;
				for(int i = 0; i< n;i++){
					if(passengers[i] == target){
						count++;
					}
				}
				
				printf("Ket qua tim kiem\n");
				printf("Gia tri can tim: %d\n", target);
				printf("vi tri: ");
				if(count==0){
					printf("Khong tim thay!\n");
					break;
				} else {
					for( int i=0; i<n;i++){
						if(passengers[i] == target){
							printf("%d\n", i+1);
						}
					}
				}
				printf("So lan suat hien: %d\n", count);
				break;
			case 0:
				printf("Thoat chuong trinh thanh cong!\n");
				break;
			default:
				printf("Lua chon khong hop le!\n");
				break;
		}
		
	}
	
}
