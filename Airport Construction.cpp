//Daljeet Singh
//105165075

#include <iostream>
#include <iomanip> 
#include <math.h>                        //declaring libraries
#include <vector>
#include <algorithm>

using namespace std;                     //global varibale

bool almost_equal(double x, double y, int ulp)      
{
    return std::abs(x-y) <= std::numeric_limits<double>::epsilon() * std::abs(x+y) * ulp
       || std::abs(x-y) < std::numeric_limits<double>::min();
}

typedef struct
{                              //declaring structure
	double x;
	double y;
}  point;

point operator+(const point p1, const point p2) { return {p1.x + p2.x, p1.y + p2.y}; }
point operator-(const point p1, const point p2) { return {p1.x - p2.x, p1.y - p2.y}; }
double distance(point p1, point p2) { return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); }
double angle(point p1, point p2) {
    double dot = p1.x*p2.x + p1.y*p2.y;
    double det = p1.x*p2.y - p1.y*p2.x;                          //declaring point
    return std::fmod(atan2(det, dot) + 2 * M_PI, 2*M_PI);
}
double max(const double a, const double b) { return a > b ? a : b; }
double min(const double a, const double b) { return a < b ? a : b; }
void swap(point &p1, point &p2) { point tmp = p1; p1 = p2; p2 = tmp; }


std::vector<int> find_polygon_orientation(const std::vector<point> points){
    std::vector<int> orientation;                                                                   //function
    point p1, p2, p_mid, cp1, cp2;
    bool is_vertical, is_vertical_c;                       //declaring variables
    double alpha, alpha_t, beta_t, alpha_c, beta_c, theta_c, x, y;
    int cpt_left, cpt_right;
    for (int k = 0; k < points.size(); ++k)
    {                                                                         //for loop
        cpt_left = 0;
        cpt_right = 0;
        p1 = points[k]; 
        p2 = points[k+1];
        p_mid = {0.5 * (p1.x  + p2.x), 0.5 * (p1.y  + p2.y)};

        for (int i = k+1; i < points.size() + k; ++i)                                //for loop
        {
            cp1 = points[(i) % points.size()];
            cp2 = points[(i + 1) % points.size()];
            alpha = is_vertical ? 0 : (double)(p1.y - p2.y) / (p1.x - p2.x);

            is_vertical_c = ((cp1.x - cp2.x) == 0);
            alpha_c = is_vertical_c ? 0 : (double)(cp1.y - cp2.y) / (cp1.x - cp2.x);              //declaring
            beta_c = cp1.y - alpha_c * cp1.x;
            
            alpha_t = (alpha == 2.544) || (alpha_c == 2544) ? 2.144 : 2.544;
            beta_t = p_mid.y - alpha_t * p_mid.x;
            
            x = NAN;
            y = NAN;
            if (is_vertical_c){
                x = cp1.x;
                y = alpha_t * x + beta_t;                                                             //if condition
            }
            else if (!almost_equal(alpha_c - alpha_t, 0, 2)) {                                                                              //else condition
                x = (beta_t - beta_c) / (alpha_c - alpha_t);
                y = (alpha_c * beta_t - alpha_t * beta_c) / (alpha_c - alpha_t);
            }

            if (!isnan(x)){
                theta_c = is_vertical_c ? (y - cp1.y) / (cp2.y - cp1.y) : (x - cp1.x) / (cp2.x - cp1.x);
                if (theta_c >= 0 && theta_c <= 1){
                    if (((x + y) < (p_mid.x + p_mid.y)))
                        cpt_left++;                                                             //if  else condition
                    else                                                                            
                        cpt_right++;
                }
            }
        }
        if (cpt_right % 2 == 1)
            orientation.push_back(1);
        else 
            orientation.push_back(-1);                                                                              //else condition
    }
    return orientation;
}

void update_inf_or_supp_point(const point cp, const point p1, const point p2, const bool is_vertical, point &p_inf, point &p_sup){
    if ((!is_vertical && cp.x >= p2.x && cp.x < p_sup.x) ||
        (is_vertical && cp.y >= p2.y && cp.y < p_sup.y)){
        p_sup = cp;                                                                                  //function
    }
    else if ((!is_vertical && cp.x > p_inf.x && cp.x <= p1.x) ||
        (is_vertical && cp.y > p_inf.y && cp.y <= p1.y)){
        p_inf = cp;
    }
}
double prolonged_segment_distance(const int i1, const int i2, const std::vector<point> points, const std::vector<int> &orientations) {
    point p1 = points[i1], p2 = points[i2], p_inf, p_sup;
    double alpha, beta;                                            //declaring variables
    bool is_vertical;
    is_vertical = ((p1.x - p2.x) == 0);
    alpha = is_vertical ? 0 : (double)(p1.y - p2.y) / (p1.x - p2.x);
    beta = p1.y - alpha * p1.x;
    p_sup = {INFINITY, alpha * INFINITY};
    p_inf = {-INFINITY, -alpha * INFINITY};
    if ((abs(i1 - i2) + 1 != points.size()) && ((angle(points[i1 == 0 ? points.size() - 1 : i1-1] - p1, p2 - p1) - angle(points[i1 == 0 ? points.size() - 1 : i1-1] - p1, points[(i1 + 1) % points.size()] - p1)) < 0)){
        return 0;
    }
    point cp1, cp2;
    std::vector<point> colinear_intersections;
    double alpha_c, beta_c, theta, theta_c, x, y;
    bool is_vertical_c;

    if ((!is_vertical && p2.x < p1.x) || (is_vertical && p2.y < p1.y))
        swap(p1, p2);
    for (int i = 0; i < points.size(); ++i)                                //for loop
    {
        cp1 = points[i];
        cp2 = points[(i + 1) % points.size()];
        is_vertical_c = ((cp1.x - cp2.x) == 0);
        alpha_c = is_vertical_c ? 0 : (double)(cp1.y - cp2.y) / (cp1.x - cp2.x);
        beta_c = cp1.y - alpha_c * cp1.x;
       
        x = NAN;
        y = NAN;
        if (is_vertical){                                                             //if condition
            x = p1.x;
            y = alpha_c * x + beta_c;
        }
        else if (is_vertical_c){
            x = cp1.x;
            y = alpha * x + beta;
        }
        else if (almost_equal(alpha_c - alpha, 0, 2)) {
            x = (beta - beta_c) / (alpha_c - alpha);                                                                              //else condition
            y = (alpha_c * beta - alpha * beta_c) / (alpha_c - alpha);
        }

        if (!isnan(x)){
            theta = is_vertical ? (y - p1.y) / (p2.y - p1.y) : (x - p1.x) / (p2.x - p1.x);
            theta_c = is_vertical_c ? (y - cp1.y) / (cp2.y - cp1.y)  : (x - cp1.x) / (cp2.x - cp1.x);

            int k = (almost_equal(x, cp1.x, 2) && almost_equal(y, cp1.y, 2)) ? i : (i + 1) % points.size(),
                bk = k == 0 ? points.size() - 1 : k - 1, ak = (k + 1) % points.size();
            point bp = points[bk], ap = points[ak];
            double bpd = is_vertical ? bp.x - p1.x : bp.y - (alpha * bp.x + beta),
                apd = is_vertical ? ap.x - p1.x : ap.y - (alpha * ap.x + beta);
            bool orientation = almost_equal(bpd, 0, 2) ? 
                        orientations[bk] * apd > 0: 
                        orientations[k] * bpd > 0;    
						bool is_limit_case = almost_equal(theta_c, 1, 2) || almost_equal(theta_c, 0, 2),
                is_normal_case = theta_c > 0 && theta_c < 1,
                is_in_segment = theta < 0 || theta > 1 || almost_equal(theta, 0, 2) || almost_equal(theta, 1, 2),
                is_limit_colinear = (almost_equal(bpd, 0, 2) || almost_equal(apd, 0, 2)) && orientation,
                is_2_sided = bpd * apd < 0;
            if ( is_normal_case || (is_limit_case && (is_limit_colinear || is_2_sided) )){                           //if condition
                if (is_limit_colinear) {
                    if(is_in_segment)
                        update_inf_or_supp_point({x, y}, p1, p2, is_vertical, p_inf, p_sup);
                    else 
                        return 0;                                                                              //else condition
                }
            }
        }
    }
    if (isinf(p_inf.x)) p_inf = p1;
    if (isinf(p_sup.x)) p_sup = p2;
    return distance(p_inf, p_sup);
}
int main()           //main function
{
    int n;
    std::vector<point> points;                       //declaring variables
    std::vector<int> orientation;
    double longest_distance = 0, x, y;

    std::cout.precision(9);
    std::cout.setf(std::ios::fixed, std:: ios::floatfield);
    while (scanf("%d", &n) != EOF) {                                          //while loop
        longest_distance = 0;
        points.clear();
        orientation.clear();
        for (int i=0 ; i<n ; i++){
            if (scanf("%lf %lf", &x, &y) == 2) {
                points.push_back({x, y});                                                             //if condition
            }
        }
        orientation = find_polygon_orientation(points);
        for (int i = 0; i < points.size(); ++i)                                //for loop
        {
            for (int j = i + 1; j < points.size(); ++j)
            {
                longest_distance =  max(prolonged_segment_distance(i, j, points, orientation), longest_distance);
            }
        }        

        cout << longest_distance << endl;                                                          //printing results
    }
    return 0;
}