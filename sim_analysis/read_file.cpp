#include "analysis_header.h"

/* CSV�ǂݍ��݂Ɏg�p����֐��i�������split) */
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

/* CSV�ǂݍ��݊֐� */
void readCSV(vector<string>& sim_data, string filename,double *f_size) {
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "failed to open file" << endl;
		exit(1);
	}

    /* 1�s���̕�������i�[����ϐ� */
    string line;

    /* �t�@�C���̍s�� */
    double data_row = 0;
    /* �t�@�C���̗� */
    double data_col = 0;
    /* �f�[�^���� */
    double data_size = 0;

    /* �t�@�C����ǂݍ���ł��� */
    while (getline(ifs, line)) {
        /* �ǂݍ��񂾕������z��Ɋi�[�i�ꎞ�I�j */
        vector<string> strvec = split(line, ',');
        /* �ꎞ�I�Ȕz����������Ă��� */
        copy(strvec.begin(), strvec.end(), back_inserter(sim_data));
        
        /* �s���X�V */
        data_row += 1;
    }
    /* �f�[�^�����擾 */
    data_size = sim_data.size();
    /* �񐔂̌v�Z */
    data_col = data_size / data_row;

    /* �z��ɒl���i�[ */
    f_size[0] = data_row;
    f_size[1] = data_col;
    f_size[2] = data_size;
}

/* �ǂݍ��񂾃f�[�^�𐮗� */
void arrangeData(vector<string>& sim_data, vector<double>& arranged_data, double* f_size) {
    /* �f�[�^�̐��� */
    for (int i = 0; i < f_size[0]; i++) {
        for (int j = 0; j < f_size[1]; j++) {
            arranged_data[j * f_size[0] + i] = stod(sim_data[f_size[1] * i + j]);
        }
    }
}

/* �f�[�^�̕����I�ȃR�s�[���쐬 */
void makeCpy(vector<double>& arranged_data, double* tmp, int start_num, int tmp_size,int d_size) {
    /* �R�s�[�J�n */
    for (int i = 0; i < tmp_size; i++) {
        int aPos = start_num + i;
        /* �R�s�[����f�[�^���c���Ă��Ȃ��Ƃ��̏��� */
        if (aPos > d_size) {
            tmp[i] = 0;
        }
        /* �R�s�[�ł���f�[�^���c���Ă���Ƃ��̏��� */
        else {
            tmp[i] = arranged_data[aPos];
        }
    }
}