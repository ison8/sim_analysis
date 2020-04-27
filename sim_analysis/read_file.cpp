#include "analysis_header.h"

/* CSV読み込みに使用する関数（文字列のsplit) */
vector<string> split(string& input, char delimiter)
{
    istringstream stream(input);
    string field;
    vector<string> result;
    while (getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}

/* CSV読み込み関数 */
void readCSV(vector<string>& sim_data, string filename,double *f_size) {
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "failed to open file" << endl;
		exit(1);
	}

    /* 1行分の文字列を格納する変数 */
    string line;

    /* ファイルの行数 */
    double data_row = 0;
    /* ファイルの列数 */
    double data_col = 0;
    /* データ総数 */
    double data_size = 0;

    /* ファイルを読み込んでいく */
    while (getline(ifs, line)) {
        /* 読み込んだ文字列を配列に格納（一時的） */
        vector<string> strvec = split(line, ',');
        /* 一時的な配列を結合していく */
        copy(strvec.begin(), strvec.end(), back_inserter(sim_data));
        
        /* 行数更新 */
        data_row += 1;
    }
    /* データ総数取得 */
    data_size = sim_data.size();
    /* 列数の計算 */
    data_col = data_size / data_row;

    /* 配列に値を格納 */
    f_size[0] = data_row;
    f_size[1] = data_col;
    f_size[2] = data_size;
}

/* 読み込んだデータを整列 */
void arrangeData(vector<string>& sim_data, vector<double>& arranged_data, double* f_size) {
    /* データの整列 */
    for (int i = 0; i < f_size[0]; i++) {
        for (int j = 0; j < f_size[1]; j++) {
            arranged_data[j * f_size[0] + i] = stod(sim_data[f_size[1] * i + j]);
        }
    }
}

/* データの部分的なコピーを作成 */
void makeCpy(vector<double>& arranged_data, double* tmp, int start_num, int tmp_size,int d_size) {
    /* コピー開始 */
    for (int i = 0; i < tmp_size; i++) {
        int aPos = start_num + i;
        /* コピーするデータが残っていないときの処理 */
        if (aPos > d_size) {
            tmp[i] = 0;
        }
        /* コピーできるデータが残っているときの処理 */
        else {
            tmp[i] = arranged_data[aPos];
        }
    }
}