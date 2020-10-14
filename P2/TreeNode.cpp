#include <iostream>
#include <cmath>
#include <vector>
#include "CityInfo.cpp"
using namespace std;

class TreeNode {
public:
    CityInfo info;
    TreeNode *NE;
    TreeNode *NW;
    TreeNode *SW;
    TreeNode *SE;  

    TreeNode(CityInfo _info) : 
        info(_info), NE(nullptr), NW(nullptr), SW(nullptr), SE(nullptr) {}

    TreeNode(CityInfo _info, TreeNode *_NE, TreeNode *_NW, TreeNode *_SW, TreeNode *_SE) : 
        info(_info), NE(_NE), NW(_NW), SW(_SW), SE(_SE) {}
};
