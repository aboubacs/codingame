#include "EquiprobableFloatMutationPolicy.h"
#include "../../../util/Rand.h"
#include "../../../util/macros.h"

EquiprobableFloatMutationPolicy::EquiprobableFloatMutationPolicy() :
AbstractMutationPolicy(){}

float EquiprobableFloatMutationPolicy::mutate(float value, float range) {
    return Rand::Double(MIN(0,value-range),MAX(1,value+range));
}