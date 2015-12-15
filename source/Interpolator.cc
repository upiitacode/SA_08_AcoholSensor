#include "Interpolator.h"

Interpolator::Interpolator(const float* x_data, const float* y_data, int data_size){
	this->x_data = x_data;
	this->y_data = y_data;
	this->data_size = data_size;
}

float Interpolator::interpolate(float x1,float x2,float y1,float y2,float x){
	float deltax = x2 - x1;
	float deltay = y2 - y1;
	float m = deltay/deltax;
	return (x-x1)*m + y1;
}

float Interpolator::logloginterpolate(float x1,float x2,float y1,float y2,float x){
	return pow(10,interpolate(log10(x1),log10(x2),log10(y1),log10(y2),log10(x)));
}

float Interpolator::logyinterpolate(float x1,float x2,float y1,float y2,float x){
	return pow(10,interpolate(x1,x2,log10(y1),log10(y2),x));
}

bool Interpolator::isGrowing(void){
	return (this->y_data[1] > this->y_data[0]);
}

bool Interpolator::isXGrowing(void){
	return (this->x_data[1] > this->x_data[0]);
}

int Interpolator::getPairIndex(float x){
	int max_index = (this->data_size-1);
	if(this->isXGrowing()){
		for(int i = 0; i < max_index; i++){
			if((this->x_data[i] <= x) && (x < this->x_data[i+1])){ 
				return i;
			}
		}
		if(x >= x_data[max_index]){
			return max_index-1;
		}else{
			return 0;
		}
	}else{
		for(int i = 0; i < max_index; i++){
			if((this->x_data[i] >= x) && (x > this->x_data[i+1])){ 
				return i;
			}
		}
		if(x <= x_data[max_index]){
			return max_index-1;
		}else{
			return 0;
		}
	}
}

float Interpolator::gety(float x){
	int index = this->getPairIndex(x);
	float x1 = this->x_data[index];
	float x2 = this->x_data[index+1];
	float y1 = this->y_data[index];
	float y2 = this->y_data[index+1];
	return interpolate(x1,x2,y1,y2,x);
}

float Interpolator::getyloglog(float x){
	int index = this->getPairIndex(x);
	float x1 = this->x_data[index];
	float x2 = this->x_data[index+1];
	float y1 = this->y_data[index];
	float y2 = this->y_data[index+1];
	return logloginterpolate(x1,x2,y1,y2,x);
}
