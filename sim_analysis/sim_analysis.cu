#include "analysis_header.h"

int main(void) {
    /* ファイル名 */
    string filename = "C:/Users/ryoin/source/repos/ison8/color_simulation_ver1/color_simulation_ver1/sim_result.csv";
    
    /* CSVファイルの値を格納するベクター */
    vector<string> sim_data;
    /* ファイルサイズ、ファイル行数、ファイル列数を格納する配列 */
    double f_size[3] = { 0,0,0 };
    
    /* CSVファイル読み込み */
    readCSV(sim_data, filename,f_size);

    /* データを入れるvector定義 */
    vector<double> arranged_data((int)f_size[2]);

    /* 読み込んだデータを整頓する */
    arrangeData(sim_data, arranged_data, f_size);
    return 0;
}