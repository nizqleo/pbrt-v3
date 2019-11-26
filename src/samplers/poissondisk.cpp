
/*
    pbrt source code is Copyright(c) 1998-2016
                        Matt Pharr, Greg Humphreys, and Wenzel Jakob.

    This file is part of pbrt.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
    IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */


// samplers/poissondisk.cpp*
#include "samplers/poissondisk.h"
#include "paramset.h"
#include "sampling.h"
#include "stats.h"
#include <vector>
#include <set>

namespace pbrt {

bool canInsert1D(Float candidate, Float cellSize, Float minDist, std::vector<Float>& grid, int D = 2){               
    int presCell = candidate/cellSize;
    for(int j = presCell-D; j <= presCell+D ; j++){
        if(j >= 0 && j < grid.size() && grid[j] >= 0 && std::abs(grid[j]-candidate) < minDist){
            return false;
        }
    }
    return true;
}
// Sampling Function Definitions
void PoissonDiskSample1D(Float *samp, int nSamples, RNG &rng, bool relaxed, int k, Float shrinkRate, int shrinkThreshold) {
    Float minDist = 1.0/float(nSamples);
    const Float cellSize = minDist;

    int gridSize = nSamples+1;
    std::vector<Float> activeList;
    std::vector<Float> grid(gridSize, -1.0);

    int cnt = 0;
	int failureCnt = 0;

    while(cnt < nSamples){
        if(activeList.empty()){
            failureCnt = 0;
            while(1){
                *samp = rng.UniformFloat();
                if(relaxed && failureCnt > shrinkThreshold){
			        minDist = shrinkRate*minDist;
			        failureCnt = 0;
		        }
                if(canInsert1D(*samp, cellSize, minDist, grid)){
                    activeList.push_back(*samp);
                    grid[int(*samp/cellSize)] = *samp;

                    samp++;cnt++;
                    break;
                }
                failureCnt++;
            }
            continue;
        }
        
        int ind = rng.UniformUInt32(activeList.size());
        Float base = activeList[ind];
        activeList.erase( activeList.begin() + ind);
        
        for(int i = 0; i < k; i++){
            Float candidate = minDist*rng.UniformFloat()+minDist;
            candidate *= rng.UniformFloat()>0.5?1:-1;
            candidate += base;
            
            if(candidate > OneMinusEpsilon || candidate < 0)
                continue;
            
            if(canInsert1D(candidate, cellSize, minDist, grid)){
                activeList.push_back(candidate);
                grid[int(candidate/cellSize)] = candidate;
                *samp = candidate;
                cnt++;
                if(cnt >= nSamples)
                    break;
                samp++;
            }
        }
    }
}

bool canInsert2D(Point2f candidate, Float cellSize,Float minDist,std::vector<std::vector<Point2f>>& grid, int D = 2){               
    int presCellx = candidate.x/cellSize;
    int presCelly = candidate.y/cellSize;
    //printf("canInsert2D..\n");
    for(int m = presCellx-D; m <= presCellx+D ; m++){
        for(int n = presCelly-D; n <= presCelly+D ; n++){
            if(m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n].x >= 0 && grid[m][n].y >= 0 && sqrt((grid[m][n].x-candidate.x)*(grid[m][n].x-candidate.x)+ (grid[m][n].y-candidate.y)*(grid[m][n].y-candidate.y))< minDist){
                return false;
            }
        }
    }
    return true;
}
void PoissonDiskSample2D(Point2f *samp, int nSamples,  RNG &rng, bool relaxed, int k, Float shrinkRate, int shrinkThreshold) {
    Float minDist = sqrt( Float(nSamples) ) / Float(nSamples);
    const Float cellSize = minDist / Sqrt2;
    assert(cellSize != 0);
    int gridSize = ( int )ceil( 1.0f / cellSize );
    std::vector<Point2f> activeList;
    std::vector<Point2f> templ(gridSize+1, {-1.0,-1.0});
    std::vector<std::vector<Point2f>> grid(gridSize+1, templ);

    int cnt = 0;
	int failureCnt = 0;

    while(cnt < nSamples){
        if(activeList.empty()){
            failureCnt = 0;
            while(1){
                samp->x = rng.UniformFloat();
                samp->y = rng.UniformFloat();
                if(failureCnt > shrinkThreshold){
			        minDist = shrinkRate*minDist;
			        failureCnt = 0;
		        }
                if(canInsert2D(*samp, cellSize, minDist, grid)){
                    activeList.push_back(*samp);
                    grid[int(samp->x/cellSize)][int(samp->y/cellSize)] = *samp;
                    samp++;cnt++;
                    break;
                }
                failureCnt++;
            }
            continue;
        }
        
        int ind = rng.UniformUInt32(activeList.size());
        Point2f base = activeList[ind];
        activeList.erase( activeList.begin() + ind);
        
        for(int i = 0; i < k; i++){
            Float r = minDist*rng.UniformFloat()+minDist;
            Float angle = 2*Pi*rng.UniformFloat();
            Point2f candidate = base;
            candidate.x += r*cos(angle);
            candidate.y += r*sin(angle);
            if(candidate.x > OneMinusEpsilon || candidate.x < 0 || 
            candidate.y > OneMinusEpsilon || candidate.y < 0)
                continue;
            
            if(canInsert2D(candidate, cellSize,minDist, grid)){
                activeList.push_back(candidate);
                grid[int(candidate.x/cellSize)][int(candidate.y/cellSize)] = candidate;
                *samp = candidate;
                cnt++;
                if(cnt >= nSamples)
                    break;
                samp++;
            }
        }
    }
}


// PoissonDiskSampler Method Definitions
void PoissonDiskSampler::StartPixel(const Point2i &p) {
    ProfilePhase _(Prof::StartPixel);
    // Generate single PoissonDisk samples for the pixel
    for (size_t i = 0; i < samples1D.size(); ++i) {
        PoissonDiskSample1D(&samples1D[i][0], samplesPerPixel, rng, relaxed, k,  shrinkRate,  shrinkThreshold);
        Shuffle(&samples1D[i][0], samplesPerPixel, 1, rng);
    }
    for (size_t i = 0; i < samples2D.size(); ++i) {
        PoissonDiskSample2D(&samples2D[i][0], samplesPerPixel, rng, relaxed, k,  shrinkRate,  shrinkThreshold);
        Shuffle(&samples2D[i][0], samplesPerPixel, 1, rng);
    }

    // Generate arrays of PoissonDisk samples for the pixel
    for (size_t i = 0; i < samples1DArraySizes.size(); ++i)
        for (int64_t j = 0; j < samplesPerPixel; ++j) {
            int count = samples1DArraySizes[i];
            PoissonDiskSample1D(&sampleArray1D[i][j * count], count, rng, relaxed, k,  shrinkRate,  shrinkThreshold);
            Shuffle(&sampleArray1D[i][j * count], count, 1, rng);
        }
    for (size_t i = 0; i < samples2DArraySizes.size(); ++i)
        for (int64_t j = 0; j < samplesPerPixel; ++j) {
            int count = samples2DArraySizes[i];
            PoissonDiskSample2D(&sampleArray2D[i][j * count], count, rng, relaxed, k,  shrinkRate,  shrinkThreshold);
            Shuffle(&sampleArray2D[i][j * count], count, 1, rng);
        }
    PixelSampler::StartPixel(p);
}

std::unique_ptr<Sampler> PoissonDiskSampler::Clone(int seed) {
    PoissonDiskSampler *ss = new PoissonDiskSampler(*this);
    ss->rng.SetSequence(seed);
    return std::unique_ptr<Sampler>(ss);
}

PoissonDiskSampler *CreatePoissonDiskSampler(const ParamSet &params) {
    bool relaxed = params.FindOneBool("relaxed", true);
    int pixelsamples = params.FindOneInt("pixelSamples", 16);
    int k = params.FindOneInt("genetatingParameter", 30);
    Float shrinkRate = params.FindOneFloat("shrinkRate", 0.99);
    int shrinkThreshold = params.FindOneInt("shrinkThreshold", 30);
    int sd = params.FindOneInt("dimensions", 4);
    return new PoissonDiskSampler(pixelsamples, relaxed, sd, k,  shrinkRate,  shrinkThreshold);
}

}  // namespace pbrt
