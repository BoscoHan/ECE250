#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include "CityInfo.cpp"
using namespace std;

class TreeNode {
    public:
    TreeNode *NE;
    TreeNode *NW;
    TreeNode *SW;
    TreeNode *SE;  
    CityInfo info;

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
            foundDuplicates[0] = true;
        
            
        //insert to NE:
        if (info->longitude >= root->info.longitude && info->latitude > root->info.latitude) {
            // cout << "NE" <<endl;
            root->NE = insertNode(root->NE, info, foundDuplicates);
        }

        //insert to NW
        if (info->longitude < root->info.longitude && info->latitude >= root->info.latitude) {
            // cout << "NW" <<endl;
            root->NW = insertNode(root->NW, info, foundDuplicates);
        }

        //insert to SW
        if (info->longitude <= root->info.longitude && info->latitude < root->info.latitude) {
            // cout << "SW" <<endl;
            root->SW = insertNode(root->SW, info, foundDuplicates);
        }

        //insert to SE
        if (info->longitude > root->info.longitude && info->latitude <= root->info.latitude) {
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

    TreeNode* findInTree(TreeNode *root, double longitude, double latitude) {
        if (root == nullptr) return nullptr;

        if (root->info.latitude == latitude && root->info.longitude == longitude) 
            return root;
        
        if (longitude > root->info.longitude && latitude > root->info.latitude) 
            return findInTree(root->NE, longitude, latitude);
        
        if (longitude < root->info.longitude && latitude > root->info.latitude) 
            return findInTree(root->NW, longitude, latitude);
        
        if (longitude < root->info.longitude && latitude < root->info.latitude) 
            return findInTree(root->SW, longitude, latitude);
        
        if (longitude > root->info.longitude && latitude < root->info.latitude) 
            return findInTree(root->SE, longitude, latitude);
        
        return nullptr;
    }

    void findMax(TreeNode *root, double &max, string const& attribute){
        if (root == nullptr) return;

        findMax(root->NE, max, attribute);
        findMax(root->NW, max, attribute);

        if (attribute == "p" && root->info.population > max) 
            max = root->info.population;
                  
        if (attribute == "r" && root->info.costOfLiving > max) 
            max = root->info.costOfLiving;

        if (attribute == "s" && root->info.avgSalary > max) 
            max = root->info.avgSalary;

        findMax(root->SW, max, attribute);
        findMax(root->SE, max, attribute);
    }


    void findMin(TreeNode *root, double &min, string const& attribute) {
        if (root == nullptr) return;

        findMin(root->NE, min, attribute);
        findMin(root->NW, min, attribute);
        
        if (attribute == "p" && root->info.population < min) 
            min = root->info.population;

        if (attribute == "r" && root->info.costOfLiving < min) 
            min = root->info.costOfLiving;

        if (attribute == "s" && root->info.avgSalary < min) 
            min = root->info.avgSalary;

        findMin(root->SW, min, attribute);
        findMin(root->SE, min, attribute);
    }

    void findTotal(TreeNode *root, double &total, string const& attribute) {
        if (root == nullptr) return;

        findTotal(root->NE, total, attribute);
        findTotal(root->NW, total, attribute);

        if (attribute == "p") 
            total += root->info.population;
                  
        if (attribute == "r") 
            total += root->info.costOfLiving;

        if (attribute == "s") 
            total += root->info.avgSalary;

        findTotal(root->SW, total, attribute);
        findTotal(root->SE, total, attribute);
    }

    //post order traversal, delete all allocated nodes
    void clearAllNodes(TreeNode *root) {
        if (root == nullptr) return;

        clearAllNodes(root->NE);
        clearAllNodes(root->NW);
        clearAllNodes(root->SE);
        clearAllNodes(root->SW);
        root = nullptr;
        delete root;
    }
};
