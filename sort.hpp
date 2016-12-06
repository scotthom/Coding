int* insertion_sort(int *a,int length)// pass ptr. 0th ellem/ length and return ptr. 0th ellem
{
	int temp;								
	int j; 		  							//initialize # inner loop;

	for (int i = 0; i < length; i++){
		j = i;

		while (j > 0 && a[j] < a[j-1]){		//compare only when you have two val and right(i) < left(i-1).
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j --;						
		}	

	}

	return a;

}

