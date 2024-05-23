#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Ingredient {
    int protein;
    int fat;
    int carbs;
    int vitamins;
    int cost;
};

int n;  // number of ingredients
vector<Ingredient> ingredients;
int min_protein, min_fat, min_carbs, min_vitamins;

vector<int> best_combination;
int best_cost = INT_MAX;
int best_protein = 0, best_fat = 0, best_carbs = 0, best_vitamins = 0;

void backtrack(int index, vector<int>& current_combination, int current_protein, int current_fat, int current_carbs, int current_vitamins, int current_cost) {
    if (current_protein >= min_protein && current_fat >= min_fat && current_carbs >= min_carbs && current_vitamins >= min_vitamins) {
        if (current_cost < best_cost || 
            (current_cost == best_cost && (current_protein > best_protein ||
                                           (current_protein == best_protein && current_fat > best_fat) ||
                                           (current_protein == best_protein && current_fat == best_fat && current_carbs > best_carbs) ||
                                           (current_protein == best_protein && current_fat == best_fat && current_carbs == best_carbs && current_vitamins > best_vitamins)))) {
            best_cost = current_cost;
            best_combination = current_combination;
            best_protein = current_protein;
            best_fat = current_fat;
            best_carbs = current_carbs;
            best_vitamins = current_vitamins;
        }
        return;
    }
    
    if (index >= n) {
        return;
    }
    
    // Include current ingredient
    current_combination.push_back(index);
    backtrack(index + 1, current_combination, current_protein + ingredients[index].protein, current_fat + ingredients[index].fat, current_carbs + ingredients[index].carbs, current_vitamins + ingredients[index].vitamins, current_cost + ingredients[index].cost);
    current_combination.pop_back();
    
    // Exclude current ingredient
    backtrack(index + 1, current_combination, current_protein, current_fat, current_carbs, current_vitamins, current_cost);
}

int main() {
    cin >> n;
    cin >> min_protein >> min_fat >> min_carbs >> min_vitamins;
    
    ingredients.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i].protein >> ingredients[i].fat >> ingredients[i].carbs >> ingredients[i].vitamins >> ingredients[i].cost;
    }
    
    vector<int> current_combination;
    backtrack(0, current_combination, 0, 0, 0, 0, 0);
    
    if (best_combination.empty()) {
        cout << "0" << endl;
    } else {
        for (int i = 0; i < best_combination.size(); ++i) {
            cout << best_combination[i] + 1 << " ";
        }
        cout << endl;
    }
    
    return 0;
}
