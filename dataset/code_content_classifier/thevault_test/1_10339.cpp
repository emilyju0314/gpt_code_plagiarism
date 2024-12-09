inline NatureResponse<prec_t> string_to_nature(string nature){
    if(nature == "robust_unbounded") return robust_unbounded;
    if(nature == "optimistic_unbounded") return optimistic_unbounded;
    if(nature == "robust_l1") return robust_l1;
    if(nature == "optimistic_l1") return optimistic_l1;
    throw invalid_argument("Unknown nature.");
}