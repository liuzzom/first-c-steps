#include <stdio.h>
#include <stdlib.h>

// Strutture//
struct matrix_t{
	size_t rows;
	size_t cols;
	double *values;
};

typedef struct matrix_t matrix_t;

// Prototipi //
//row=riga; col=colonna; rows=righe; cols=colonne;//

matrix_t *  // Alloca la matrice //
matrix_new(size_t rows, size_t cols);

void // Libera la matrice // 
matrix_free(matrix_t *m);

size_t // Conta il numero di righe //
matrix_number_of_rows(matrix_t *m);

size_t // Conta il numero di colonne //
matrix_number_of_cols(matrix_t *m);

void //Inserisce un valore nella matrice //
matrix_set(matrix_t *m, size_t row, size_t col, double value);

double //Da all'utente un valore dalla matrice //
matrix_get(matrix_t *m, size_t row, size_t col);

double * //Raggiunge una "posizione" nella matrice //
matrix_get_value_pointer(matrix_t *m, size_t row, size_t col);

void // Stampa la matrice //
matrix_print(matrix_t *m);

// Funzioni //

matrix_t *
matrix_new(size_t rows, size_t cols){
	matrix_t *new;
	
	new=malloc(sizeof(matrix_t));
	if(new){
		new->rows=rows;
		new->cols=cols;
		new->values=calloc(rows*cols, sizeof(double));
		if(!new->values){
			free(new);
			return NULL;
		}
	}
	return new;
}

void
matrix_free(matrix_t *m){
	free(m->values);
	free(m);
}

size_t
matrix_number_of_rows(matrix_t *m){
	return m->rows;
}

size_t
matrix_number_of_cols(matrix_t *m){
	return m->cols;
}

double*
matrix_get_value_pointer(matrix_t *m, size_t row, size_t col){
	size_t k, cols;
	
	cols=matrix_number_of_cols(m);
	k=row*cols+col;
	
	return m->values+k;
}

void
matrix_set(matrix_t *m, size_t row, size_t col, double value){
	double *value_ptr;
	
	value_ptr=matrix_get_value_pointer(m, row, col);
	*value_ptr=value;
}

double
matrix_get(matrix_t *m, size_t row, size_t col){
	double *value_ptr;
	
	value_ptr=matrix_get_value_pointer(m, row, col);
	return *value_ptr;
}

void
matrix_print(matrix_t *m){
	size_t rows, cols;
	size_t row, col;
	
	rows=matrix_number_of_rows(m);
	cols=matrix_number_of_cols(m);
	
	for(row=0; row<rows; row++){
		for(col=0; col<cols; col++){
			printf("%lf ", matrix_get(m, row, col));
		}
		printf("\n");
	}
}


// Main //
int
main(int argc, char **argv){
	matrix_t *a;
	
	a=matrix_new(4,4);
	if(a){
		matrix_set(a, 0,0, 1.0);
		matrix_set(a, 1,1, 2.0);
		matrix_set(a, 2,2, 3.0);
		matrix_set(a, 3,3, 4.0);
		
		matrix_print(a);
		matrix_free(a);
		a=NULL;
	}
	
return 0;
}
