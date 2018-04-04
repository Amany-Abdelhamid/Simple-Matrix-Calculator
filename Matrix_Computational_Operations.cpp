#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	float a1[100][100];
	string m1; getline(cin, m1); int x = m1.length();
	if ((m1[0] != '[') || (m1[x-1] != ']'))
	{
		cout << "ERROR";
		exit(1);
	}
	for (int i = 1; i < x - 1; i++)
	{
		switch (m1[i])
		{
		case ' ': case ';': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':case'.':case'-': break;
		default: cout << "ERROR"; exit(1);
		}
		if ((m1[i] == ' ') && (m1[i + 1] == ' '))
		{
			cout << "ERROR"; exit(1);
		}
		else if ((m1[i] == ';') && (m1[i + 1] == ';'))
		{
			cout << "ERROR"; exit(1);
		}
		else if (((m1[i] == ' ') && (m1[i + 1] == ';')) || ((m1[i] == ';') && (m1[i + 1] == ' ')))
		{
					cout << "ERROR"; exit(1);
		}
	}
	int nelement1 = 1; int nrow1 = 1; int k1 = 0; int n1 = 0; string q1; int j1 = 1;
	for (int i = 1; i < x; i++)
	{
		 
		if ((m1[i] == ';') || (m1[i] == ' ') || (m1[i] == ']'))
		{
			 
			q1 = m1.substr(j1, i - 1);
			j1= i + 1;
		}
		if (m1[i] == ' ')
		{
			a1[n1][k1] = atof(q1.c_str());
			k1++; nelement1++;
		}
		if (m1[i] == ';')
		{
			a1[n1][k1] = atof(q1.c_str());
			n1++; k1 = 0; nelement1++; nrow1++;
		}
		if (m1[i] == ']')
		{
			a1[n1][k1] = atof(q1.c_str());
		}
	}
	if ((nelement1%nrow1)!=0)
	{
		cout << "ERROR";
		exit(1);
	}
	char b; cin >> b; cin.ignore();
	float a2[100][100]; string m2;
	if ((b == '+') || (b == '-') || (b == '*') || (b == '/'))
	{
		getline(cin, m2); int l = m2.length();
		if ((m2[0] != '[') || (m2[l - 1] != ']'))
		{
			cout << "ERROR";
			exit(1);
		}
		for (int i = 1; i < l - 1; i++)
		{
			switch (m2[i])
			{
			case ' ': case ';': case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':case'.':case'-': break;
			default: cout << "ERROR"; exit(1);
			}
			if ((m2[i] == ' ') && (m2[i + 1] == ' '))
			{
				cout << "ERROR"; exit(1);
			}
			else if ((m2[i] == ';') && (m2[i + 1] == ';'))
			{
				cout << "ERROR"; exit(1);
			}
			else if (((m2[i] == ' ') && (m2[i + 1] == ';')) || ((m2[i] == ';') && (m2[i + 1] == ' ')))
			{
				cout << "ERROR"; exit(1);
			}
		}
		int nelement2 = 1; int nrow2 = 1; int k2 = 0; int n2 = 0; string q2; int j2 = 1;
		for (int i = 1; i < l; i++)
		{

			if ((m2[i] == ';') || (m2[i] == ' ') || (m2[i] == ']'))
			{

				q2 = m2.substr(j2, i - 1);
				j2 = i + 1;
			}
			if (m2[i] == ' ')
			{
				a2[n2][k2] = atof(q2.c_str());
				k2++; nelement2++;
			}
			if (m2[i] == ';')
			{
				a2[n2][k2] = atof(q2.c_str());
				n2++; k2 = 0; nelement2++; nrow2++;
			}
			if (m2[i] == ']')
			{
				a2[n2][k2] = atof(q2.c_str());
			}
		}
		if ((nelement2%nrow2) != 0)
		{
			cout << "ERROR";
			exit(1);
		}
		float f; string str;
		if ((b == '+') || (b == '-'))
		{
			if ((nelement1 != nelement2) && (nrow1 != nrow2))
			{
				cout << "ERROR";
				exit(1);
			}
			cout << "[";
			for (int i = 0; i < nrow1; i++)
			{
				n1 = n2 = i;
				for (int s = 0; s < (nelement1 / nrow1); s++)
				{
					k1 = k2 = s;
					if (b == '+')
						f = a1[n1][k1] + a2[n2][k2];
					if (b == '-')
						f = a1[n1][k1] - a2[n2][k2];
					cout << f;
					if (s != (nelement1 / nrow1) - 1)
						cout << " ";
				}
				if (i != (nrow1 - 1))
					cout << ";";
			}
			cout << "]" << endl;
		}
		float sum = 0;
		if (b == '*')
		{
			if ((nelement1 / nrow1) != nrow2)
			{
				cout << "ERROR";
				exit(1);
			}
			cout << "[";
			for (int i = 0; i < nrow1; i++)
			{
				n1 = i;
				for (int s = 0; s < (nelement2 / nrow2); s++)
				{
					k2 = s;
					for (int j = 0; j < nrow2; j++)
					{
						k1 = n2 = j;
						sum += (a1[n1][k1] * a2[n2][k2]);
					}
					cout << sum;
					sum = 0;
					if (s != (nelement2 / nrow2) - 1)
						cout << " ";
				}
				if (i != (nrow1 - 1))
					cout << ";";
			}
			cout << "]" << endl;
		}
		if (b == '/')
		{
			if ((nrow2 != (nelement2 / nrow2)) || (nrow2 != (nelement1 / nrow1)))
			{
				cout << "ERROR";
				exit(1);
			}

			float a4[100][100];
			for (int i = 0; i < nrow2; i++)
			{
				for (int j = 0; j < nrow2; j++)
				{
					a4[i][i] = 1;
					if (i != j)
						a4[i][j] = 0;
				}
			}

			float a5[100][100]; float d, t;
			for (int i = 0; i < nrow2; i++)
			{
				for (int j = 0; j < nrow2; j++)
				 a5[i][j] = a2[i][j];
			}

			for (int k = 0; k < nrow2 - 1; k++)
			{
				for (int i = k + 1; i < nrow2; i++)
				{
					t = a5[i][k] / a5[k][k];
					for (int j = 0; j < nrow2; j++)
					{
						a5[i][j] = a5[i][j] - (t * a5[k][j]);
						a4[i][j] = a4[i][j] - (t * a4[k][j]);
					}
				}
			}
			d = a5[0][0];
			for (int i = 1; i < nrow2; i++)
			{
				d = d*a5[i][i];
			}
			if (d == 0)
			{
				cout << "ERROR";
				exit(1);
			}
			for (int k = nrow2 - 1; k > 0; k--)
			{
				for (int i = k - 1; i >= 0; i--)
				{
					t = a5[i][k] / a5[k][k];
					for (int j = 0; j < nrow2; j++)
					{
						a5[i][j] = a5[i][j] - (t * a5[k][j]);
						a4[i][j] = a4[i][j] - (t * a4[k][j]);
					}
				}
			}

			for (int i = 0; i < nrow2; i++)
			{
				t = 1 / a5[i][i];
				for (int j = 0; j < nrow2; j++)
				{
					a5[i][j] = (a5[i][j] * t);
					a4[i][j] = (a4[i][j] * t);
				}
			}
			cout << "[";
			for (int i = 0; i < nrow1; i++)
			{
				n1 = i;
				for (int s = 0; s < (nelement2 / nrow2); s++)
				{
					k2 = s;
					for (int j = 0; j < nrow2; j++)
					{
						k1 = n2 = j;
						sum += (a1[n1][k1] * a4[n2][k2]);
					}
					cout << sum;
					sum = 0;
					if (s != (nelement2 / nrow2) - 1)
						cout << " ";
				}
				if (i != (nrow1 - 1))
					cout << ";";
			}
			cout << "]" << endl;
		}
	}
		if (b == '^')
		{
			if (nrow1 != (nelement1 / nrow1))
			{
				cout << "ERROR";
				exit(1);
			}
			int pow; cin >> pow;
			if (pow < 2)
			{
				cout << "ERROR";
				exit(1);
			}
			cout << "["; int k2, n2, n3, k3; float a2[100][100], a3[100][100];
			for (int i = 0; i < nrow1; i++)
			{
				n3 = n1 = i;
				for (int j = 0; j < (nelement1 / nrow1); j++)
				{
					k3 = k1 = j;
					a3[n3][k3] = a1[n1][k1];
				}
			}
			for (int i = 1; i < pow; i++)
			{
				float sum = 0;
				for (int j = 0; j < nrow1; j++)
				{
					n3 = n2 = j;
					for (int s = 0; s < (nelement1 / nrow1); s++)
					{
						k1 = k2 = s;
						for (int u = 0; u < nrow1; u++)
						{
							k3 = n1 = u;
							sum += (a3[n3][k3] * a1[n1][k1]);
						}
						a2[n2][k2] = sum;
						sum = 0;
					}
				}
				if (i != pow - 1)
				{
					for (int i = 0; i < nrow1; i++)
					{
						n2 = n3 = i;
						for (int j = 0; j < (nelement1 / nrow1); j++)
						{
							k2 = k3 = j;
							a3[n3][k3] = a2[n2][k2];
						}
					}
				}
			}
			for (int i = 0; i < nrow1; i++)
			{
				for (int j = 0; j < (nelement1 / nrow1); j++)
				{
					cout << a2[i][j];
					if (j != (nelement1 / nrow1) - 1)
						cout << " ";
				}
				if (i != (nrow1 - 1))
					cout << ";";
				if (i == (nrow1 - 1))
					cout << "]" << endl;
			}
		}
		if (b == 'T')
		{
			float a2[100][100];
			for (int i = 0; i < nrow1; i++)
			{
				n1 = i;
				for (int j = 0; j < (nelement1 / nrow1); j++)
				{
					k1 = j;
					a2[k1][n1] = a1[n1][k1];
				}
			}
			cout << "[";
			for (int i = 0; i < (nelement1 / nrow1); i++)
			{
				for (int j = 0; j < nrow1; j++)
				{
					cout << a2[i][j];
					if (j != nrow1 - 1)
						cout << " ";
				}
				if (i != (nelement1 / nrow1) - 1)
					cout << ";";
				else
					cout << "]" << endl;
			}
		}
		if ((b == 'D') || (b == 'I'))
		{
			if (nrow1 != (nelement1 / nrow1))
			{
				cout << "ERROR";
				exit(1);
			}

			float a4[100][100];
			for (int i = 0; i < nrow1; i++)
			{
				for (int j = 0; j < nrow1; j++)
				{
					a4[i][i] = 1;
					if (i != j)
						a4[i][j] = 0;
				}
			}

			float a2[100][100], a3[100][100]; float d, t;
			for (int i = 0; i < nrow1; i++)
			{
				for (int j = 0; j < nrow1; j++)
					a3[i][j] = a2[i][j] = a1[i][j];
			}

			for (int k = 0; k < nrow1 - 1; k++)
			{
				for (int i = k + 1; i < nrow1; i++)
				{
					t = a2[i][k] / a2[k][k];
					for (int j = 0; j < nrow1; j++)
					{
						a2[i][j] = a2[i][j] - (t * a2[k][j]);
						a4[i][j] = a4[i][j] - (t * a4[k][j]);
					}
				}
			}
			d = a2[0][0];
			for (int i = 1; i < nrow1; i++)
			{
				d = d*a2[i][i];
			}
			if (b == 'D')
				cout << d << endl;
			if (b == 'I')
			{
				if (d == 0)
				{
					cout << "ERROR";
					exit(1);
				}
				for (int k = nrow1 - 1; k > 0; k--)
				{
					for (int i = k - 1; i >= 0; i--)
					{
						t = a2[i][k] / a2[k][k];
						for (int j = 0; j < nrow1; j++)
						{
							a2[i][j] = a2[i][j] - (t * a2[k][j]);
							a4[i][j] = a4[i][j] - (t * a4[k][j]);
						}
					}
				}

				for (int i = 0; i < nrow1; i++)
				{
					t = 1 / a2[i][i];
					for (int j = 0; j < nrow1; j++)
					{
						a2[i][j] = (a2[i][j] * t);
						a4[i][j] = (a4[i][j] * t);
					}
				}


				cout << "[";
				for (int i = 0; i < nrow1; i++)
				{
					for (int j = 0; j < nrow1; j++)
					{
						cout << a4[i][j];
						if (j != nrow1 - 1)cout << " ";
					}
					if (i != nrow1 - 1)cout << ";";
				}
				cout << "]" << endl;
			}
		}
	return 0;
}