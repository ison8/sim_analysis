#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/* �֐���` */
int main(void);		// main�֐�

/* csv�ǂݍ��݊֐� */
void readCSV(vector<string>& sim_data, string filename, double* f_size);

/* �ǂݍ��񂾃f�[�^�𐮗� */
void arrangeData(vector<string>& sim_data, vector<double>& arranged_data, double* f_size);
