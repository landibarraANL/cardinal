/*

   The MIT License (MIT)

   Copyright (c) 2017 Tim Warburton, Noel Chalmers, Jesse Chan, Ali Karakus

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.

 */

#include <stdio.h>
#include <stdlib.h>
#include "mesh.h"
#include "mesh3D.h"

void meshPhysicalNodesQuad3D(mesh_t* mesh)
{
  mesh->x = (dfloat*) calloc(mesh->Nelements * mesh->Np,sizeof(dfloat));
  mesh->y = (dfloat*) calloc(mesh->Nelements * mesh->Np,sizeof(dfloat));
  mesh->z = (dfloat*) calloc(mesh->Nelements * mesh->Np,sizeof(dfloat));

  int cnt = 0;
  for(int e = 0; e < mesh->Nelements; ++e) { /* for each element */
    int id = e * mesh->Nverts;

    dfloat xe1 = mesh->EX[id + 0]; /* x-coordinates of vertices */
    dfloat xe2 = mesh->EX[id + 1];
    dfloat xe3 = mesh->EX[id + 2];
    dfloat xe4 = mesh->EX[id + 3];

    dfloat ye1 = mesh->EY[id + 0]; /* y-coordinates of vertices */
    dfloat ye2 = mesh->EY[id + 1];
    dfloat ye3 = mesh->EY[id + 2];
    dfloat ye4 = mesh->EY[id + 3];

    dfloat ze1 = mesh->EZ[id + 0]; /* z-coordinates of vertices */
    dfloat ze2 = mesh->EZ[id + 1];
    dfloat ze3 = mesh->EZ[id + 2];
    dfloat ze4 = mesh->EZ[id + 3];

    for(int n = 0; n < mesh->Np; ++n) { /* for each node */
      /* (r,s) coordinates of interpolation nodes*/
      dfloat rn = mesh->r[n];
      dfloat sn = mesh->s[n];

      /* physical coordinate of interpolation node */
      dfloat xlin =
        +0.25 * (1 - rn) * (1 - sn) * xe1
        + 0.25 * (1 + rn) * (1 - sn) * xe2
        + 0.25 * (1 + rn) * (1 + sn) * xe3
        + 0.25 * (1 - rn) * (1 + sn) * xe4;

      dfloat ylin =
        +0.25 * (1 - rn) * (1 - sn) * ye1
        + 0.25 * (1 + rn) * (1 - sn) * ye2
        + 0.25 * (1 + rn) * (1 + sn) * ye3
        + 0.25 * (1 - rn) * (1 + sn) * ye4;

      dfloat zlin =
        +0.25 * (1 - rn) * (1 - sn) * ze1
        + 0.25 * (1 + rn) * (1 - sn) * ze2
        + 0.25 * (1 + rn) * (1 + sn) * ze3
        + 0.25 * (1 - rn) * (1 + sn) * ze4;

      //      printf("xlin=%g, ylin=%g, zlin=%g\n", xlin, ylin, zlin);

      // project to sphere
      dfloat rlin = sqrt(xlin * xlin + ylin * ylin + zlin * zlin);
      mesh->x[cnt] = xlin / rlin;
      mesh->y[cnt] = ylin / rlin;
      mesh->z[cnt] = zlin / rlin;

      ++cnt;
    }
  }
}
