#include "vector.h"

bool vector_init(vector_t *v, size_t capacity) {
	v->data = (int*) malloc(capacity * sizeof(int));

	if(v->data) {
		v->size     = 0;
		v->capacity = capacity;
		return true;
	}

	return false;
}

size_t vector_size(vector_t *v) {
	return v->size;
}

size_t vector_capacity(vector_t *v) {
	return v->capacity;
}

bool vector_empty(vector_t *v) {
	return v->size ? false : true;
}

int* vector_begin(vector_t *v) {
	return v->data;
}

int* vector_end(vector_t *v) {
	return v->size ? v->data + v->size - 1 : v->data;
}

int vector_front(vector_t *v) {
	return v->size ? v->data[0] : 0;
}

int vector_back(vector_t *v) {
	return v->size ? v->data[v->size-1] : 0;
}

int vector_at(vector_t *v, ssize_t index) {
	if(index < 0)
		return index >= -v->size ? v->data[-(index+1)] : 0;	
	else 
		return index < v->size ? v->data[index] : 0;
}

void vector_clear(vector_t *v) {
	free(v->data);
	v->size = 0;
}

void vector_swap(vector_t *v, vector_t *w) {
	vector_t u = *v;
	*v = *w;
	*w =  u;
}
	
bool vector_reserve(vector_t *v, size_t capacity) {
	int *data = (int*) realloc(v->data, capacity * sizeof(int));

	if(data) {
		v->data = data;
		v->capacity = capacity;
		if(v->size > capacity)
			v->size = capacity;
		return true;
	}
		
	return false;
}

bool vector_shrink_to_fit(vector_t *v) {
	return vector_reserve(v, v->size);
}

bool vector_resize(vector_t *v, size_t size) {
	bool status = true;
	int *p;
	size_t i;

	if(size > v->capacity) {
		for(i = v->capacity; i < size; i *= 2)
			continue;
		status = vector_reserve(v, i);
	}

	if(status) {
		for(p = v->data+v->size; p < v->data+size; ++p)
			*p = 0;		
		v->size = size;
	}

	return status;
}

bool vector_push_back(vector_t *v, int data) {
	bool status = true;

	if(v->size == v->capacity)
		status = vector_reserve(v, v->capacity*2);

	if(status) {
		v->size += 1;	
		v->data[v->size-1] = data;
	}

	return status;
}

int vector_pop_back(vector_t *v) {
	int data = vector_back(v);
	if(v->size)
		v->size -= 1;
	return data;
}

bool vector_assign(vector_t *v, size_t count, int value) {
	bool status = true;
	size_t i;

	if(v->capacity < count) {
		for(i = v->capacity; i < count; i *= 2)
			continue;
		status = vector_reserve(v, i);
	}

	if(status) {
		for(i = 0; i < count; ++i)
			v->data[i] = value;
		v->size = count;
	}

	return status;
}
