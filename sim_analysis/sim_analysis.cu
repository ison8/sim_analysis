#include "analysis_header.h"

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
    return 0;
}