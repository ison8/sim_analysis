#include "analysis_header.h"

template<int BLOCK_SIZE> __global__ void calcAve(double *tmp,double *ave,double white_x,double white_y, double array_row, double array_col) {
    /* ���b�V���p�ϐ� */
    double mesh_x_start = (double)blockIdx.x * 0.2;
    double mesh_x_end = (double)blockIdx.x * 0.2 + 0.2;
    double mesh_y_start = (double)threadIdx.x * 0.2;
    double mesh_y_end = (double)threadIdx.x * 0.2 + 0.2;

    /* ���όv�Z */
    double ave_deg = 0;
    double ave_count = 0;


}

int main(void) {
    /* �t�@�C���� */
    string filename = "C:/Users/ryoin/source/repos/ison8/color_simulation_ver1/color_simulation_ver1/sim_result.csv";
    
    /* CSV�t�@�C���̒l���i�[����x�N�^�[ */
    vector<string> sim_data;
    /* �t�@�C���T�C�Y�A�t�@�C���s���A�t�@�C���񐔂��i�[����z�� */
    double f_size[3] = { 0,0,0 };
    
    /* CSV�t�@�C���ǂݍ��� */
    readCSV(sim_data, filename,f_size);

    /* �f�[�^������vector��` */
    vector<double> arranged_data((int)f_size[2]);

    /* �ǂݍ��񂾃f�[�^�𐮓ڂ��� */
    arrangeData(sim_data, arranged_data, f_size);

    /* CUDA�֓n���p�̕ϐ� */
    double* tmp;
    double* ave;

    double white_x = arranged_data[0];
    double white_y = arranged_data[f_size[0]];

    /* �z��̓��I�m�� */
    tmp = new double[f_size[1] * 3 * 50];
    ave = new double[45 * 45 * 2];

    /* tmp�̑傫�� */
    int tmp_size = f_size[0] * 3 * 50;

    /* �u���b�N�T�C�Y�A�O���b�h�T�C�Y */
    int grid = 45, block = 45;

    /* for���ŉ񂵂ĕ��ς��v�Z���Ă��� */
    for (int i = 0; i < ((int)f_size[2]); i += tmp_size) {
 
    }
    makeCpy(arranged_data, tmp, 0,tmp_size,f_size[2]);

    return 0;
}