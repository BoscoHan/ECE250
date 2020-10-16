#include <iostream>
#include <cmath>
#include <vector>
#include "CityInfo.cpp"
using namespace std;

class TreeNode {
    private:
        CityInfo info;
        TreeNode *NE;
        TreeNode *NW;
        TreeNode *SW;
        TreeNode *SE;  

    public:
        TreeNode(CityInfo _info) : 
            info(_info), NE(nullptr), NW(nullptr), SW(nullptr), SE(nullptr) {}

        TreeNode(CityInfo _info, TreeNode *_NE, TreeNode *_NW, TreeNode *_SW, TreeNode *_SE) : 
            info(_info), NE(_NE), NW(_NW), SW(_SW), SE(_SE) {}

        void printAttributes(TreeNode *node) {
            cout << node->info.name <<endl;
            cout << node->info.longitude <<endl;
            cout << node->info.latitude <<endl;
            cout << node->info.population <<endl;
            cout << node->info.costOfLiving <<endl;
            cout << node->info.avgSalary <<endl;
        }

        //lat = y, long = x
        TreeNode* insertNode(TreeNode *root, CityInfo *info, bool foundDuplicates[]) {               
            if (root == NULL) 
                return new TreeNode(*info);
            
            if (root->info.latitude == info->latitude && root->info.longitude == info->longitude) 
            {
                foundDuplicates[0] = true;
                return nullptr;
            }
                
            //insert to NE:
            if (info->longitude > root->info.longitude && info->latitude > root->info.latitude) {
                // cout << "NE" <<endl;
                root->NE = insertNode(root->NE, info, foundDuplicates);
            }

            //insert to NW
            if (info->longitude < root->info.longitude && info->latitude > root->info.latitude) {
                // cout << "NW" <<endl;
                root->NW = insertNode(root->NW, info, foundDuplicates);
            }

            //insert to SW
            if (info->longitude < root->info.longitude && info->latitude < root->info.latitude) {
                // cout << "SW" <<endl;
                root->SW = insertNode(root->SW, info, foundDuplicates);
            }

            //insert to SE
            if (info->longitude > root->info.longitude && info->latitude < root->info.latitude) {
                // cout << "SE" <<endl;
                root->SE = insertNode(root->SE, info, foundDuplicates);
            }
            
            return root;
        }

        int countNodes(TreeNode *root) {
            if (root == nullptr) return 0;
            return countNodes(root->NE) + countNodes(root->NW) + countNodes(root->SE) + countNodes(root->SW)+1;
        }

        void printInorder(TreeNode * root, vector<string> &list) {
            if (root == nullptr) return;

            printInorder(root->NE, list);
            printInorder(root->NW, list);
            list.push_back(root->info.name);
            printInorder(root->SW, list);
            printInorder(root->SE, list);
        }

};
