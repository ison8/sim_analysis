#include "analysis_header.h"

template<int BLOCK_SIZE> __global__ void calcAve(double *tmp,double *ave,double white_x,double white_y, double array_row, double array_col) {
    /* メッシュ用変数 */
    double mesh_x_start = (double)blockIdx.x * 0.2;
    double mesh_x_end = (double)blockIdx.x * 0.2 + 0.2;
    double mesh_y_start = (double)threadIdx.x * 0.2;
    double mesh_y_end = (double)threadIdx.x * 0.2 + 0.2;

    /* 平均計算 */
    double ave_deg = 0;
    double ave_count = 0;


}

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

    /* CUDAへ渡す用の変数 */
    double* tmp;
    double* ave;

    double white_x = arranged_data[0];
    double white_y = arranged_data[f_size[0]];

    /* 配列の動的確保 */
    tmp = new double[f_size[1] * 3 * 50];
    ave = new double[45 * 45 * 2];

    /* tmpの大きさ */
    int tmp_size = f_size[0] * 3 * 50;

    /* ブロックサイズ、グリッドサイズ */
    int grid = 45, block = 45;

    /* for文で回して平均を計算していく */
    for (int i = 0; i < ((int)f_size[2]); i += tmp_size) {
 
    }
    makeCpy(arranged_data, tmp, 0,tmp_size,f_size[2]);

    return 0;
}