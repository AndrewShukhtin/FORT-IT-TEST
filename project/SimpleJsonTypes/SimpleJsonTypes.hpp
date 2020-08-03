#ifndef PROJECT_SIMPLEJSON_SIMPLEJSONDATA_HPP_
#define PROJECT_SIMPLEJSON_SIMPLEJSONDATA_HPP_

#include <string>
#include <unordered_set>

// NOTE: Пример представления данных
// [{
//   { "_id" : idNumber1,
//     "data" : "value1"
//   },
//   { "_id" : idNumber2,
//     "data" : "value2"
//   },
//   { "_id" : idNumber3,
//     "data" : "value3"
//   }
//   ...
// }]

using SimpeJsonContainer = std::unordered_set<std::string>;
using SimpleJsonValue = std::string;

#endif  // PROJECT_SIMPLEJSON_SIMPLEJSONDATA_HPP_
