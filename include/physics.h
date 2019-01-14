#ifndef REFLECS_COMPONENTS_PHYSICS_H
#define REFLECS_COMPONENTS_PHYSICS_H

#include "bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsSpeed {
    float value;
} EcsSpeed;

typedef EcsVec2 EcsVelocity2D;

typedef EcsVec3 EcsVelocity3D;

typedef struct EcsAngularSpeed {
    float value;
} EcsAngularSpeed;

typedef EcsVec3 EcsAngularVelocity;

typedef EcsVec4 EcsAABB;
typedef EcsVec2 EcsPoint2D;

typedef struct EcsCircle2DCollider {
    float radius;
} EcsCircleCollider;

typedef struct EcsPolygon2DCollider {
    EcsPoint2D *points;
    int8_t point_count; //MAX 128
} EcsPolygonCollider;

typedef struct EcsComponentsPhysicsHandles {
    EcsHandle Speed;
    EcsHandle Velocity2D;
    EcsHandle Velocity3D;
    EcsHandle AngularSpeed;
    EcsHandle AngularVelocity;
} EcsComponentsPhysicsHandles;

void EcsComponentsPhysics(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsPhysics_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Speed);\
    EcsDeclareHandle(handles, Velocity2D);\
    EcsDeclareHandle(handles, Velocity3D);\
    EcsDeclareHandle(handles, AngularSpeed);\
    EcsDeclareHandle(handles, AngularVelocity);

#ifdef __cplusplus
}
#endif

#endif