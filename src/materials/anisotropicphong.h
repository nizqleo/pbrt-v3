
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

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_MATERIALS_ANISOTROPICPHONG_H
#define PBRT_MATERIALS_ANISOTROPICPHONG_H

// materials/anisotropicphong.h*
#include "pbrt.h"
#include "material.h"

namespace pbrt {

// AnisotropicPhongMaterial Declarations
class AnisotropicPhongMaterial : public Material {
  public:
    // AnisotropicPhongMaterial Public Methods
    AnisotropicPhongMaterial(const std::shared_ptr<Texture<Spectrum>> &Rd,
                  const std::shared_ptr<Texture<Spectrum>> &Rs,
                  const std::shared_ptr<Texture<Float>> &Nu,
                  const std::shared_ptr<Texture<Float>> &Nv,
                  const std::shared_ptr<Texture<Float>> &bumpMap)
        : RD(Rd), 
        RS(Rs), 
        NU(Nu), 
        NV(Nv) , 
        bumpMap(bumpMap) {
        }
    void ComputeScatteringFunctions(SurfaceInteraction *si, MemoryArena &arena,
                                    TransportMode mode,
                                    bool allowMultipleLobes) const;

  private:
    // AnisotropicPhongMaterial Private Data
    // std::shared_ptr<Texture<Spectrum>> RD, RS;
    // std::shared_ptr<Texture<Float>> NV,NU;
    std::shared_ptr<Texture<Spectrum>>  RD, RS;
    std::shared_ptr<Texture<Float>>  NV, NU;
    std::shared_ptr<Texture<Float>> bumpMap;
};

AnisotropicPhongMaterial *CreateAnisotropicPhongMaterial(const TextureParams &mp);

}  // namespace pbrt

#endif  // PBRT_MATERIALS_ANISOTROPICPHONG_H
