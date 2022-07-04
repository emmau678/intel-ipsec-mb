/*******************************************************************************
  Copyright (c) 2022, Intel Corporation

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

      * Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * Neither the name of Intel Corporation nor the names of its contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#include "include/sha_mb_mgr.h"

IMB_JOB *submit_job_sha1_avx(MB_MGR_SHA_1_OOO *state, IMB_JOB *job);
IMB_JOB *flush_job_sha1_avx(MB_MGR_SHA_1_OOO *state, IMB_JOB *job);

IMB_JOB *submit_job_sha224_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *flush_job_sha224_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);

IMB_JOB *submit_job_sha256_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);
IMB_JOB *flush_job_sha256_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job);

/* ========================================================================== */
/*
 * SHA1 MB API
 */

IMB_DLL_LOCAL
IMB_JOB *submit_job_sha1_avx(MB_MGR_SHA_1_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_1(state, job, 4, 1, 1,
                                        IMB_SHA1_BLOCK_SIZE, SHA1_PAD_SIZE,
                                        call_sha1_mult_avx_from_c, 0);
}

IMB_DLL_LOCAL
IMB_JOB *flush_job_sha1_avx(MB_MGR_SHA_1_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_1(state, job, 4, 0, 1,
                                        IMB_SHA1_BLOCK_SIZE, SHA1_PAD_SIZE,
                                        call_sha1_mult_avx_from_c, 0);
}

/* ========================================================================== */
/*
 * SHA224 MB API
 */

IMB_DLL_LOCAL
IMB_JOB *submit_job_sha224_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_256(state, job, 4, 1, 224,
                                        IMB_SHA_256_BLOCK_SIZE, SHA224_PAD_SIZE,
                                        call_sha_256_mult_avx_from_c, 0);
}

IMB_DLL_LOCAL
IMB_JOB *flush_job_sha224_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_256(state, job, 4, 0, 224,
                                        IMB_SHA_256_BLOCK_SIZE, SHA224_PAD_SIZE,
                                        call_sha_256_mult_avx_from_c, 0);
}

/* ========================================================================== */
/*
 * SHA256 MB API
 */

IMB_DLL_LOCAL
IMB_JOB *submit_job_sha256_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_256(state, job, 4, 1, 256,
                                        IMB_SHA_256_BLOCK_SIZE, SHA256_PAD_SIZE,
                                        call_sha_256_mult_avx_from_c, 0);
}

IMB_DLL_LOCAL
IMB_JOB *flush_job_sha256_avx(MB_MGR_SHA_256_OOO *state, IMB_JOB *job)
{
        return submit_flush_job_sha_256(state, job, 4, 0, 256,
                                        IMB_SHA_256_BLOCK_SIZE, SHA256_PAD_SIZE,
                                        call_sha_256_mult_avx_from_c, 0);
}
