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

/* 関数定義 */
int main(void);		// main関数

/* csv読み込み関数 */
void readCSV(vector<string>& sim_data, string filename, double* f_size);

/* 読み込んだデータを整列 */
void arrangeData(vector<string>& sim_data, vector<double>& arranged_data, double* f_size);
