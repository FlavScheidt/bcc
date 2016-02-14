likwid-perfctr -C 0 -g FLOPS_DP -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat > _256_flops_dp.dat
likwid-perfctr -C 0 -g MEM -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat > _256_mem.dat
likwid-perfctr -C 0 -g CACHE -m ./pdeSolver -nx 256 -ny 256 -i 10 -m gs -o _512.dat > _256_cache.dat

likwid-perfctr -C 0 -g FLOPS_DP -m ./pdeSolver -nx 512 -ny 512 -i 10 -m gs -o _512.dat > _512_flops_dp.dat
likwid-perfctr -C 0 -g MEM -m ./pdeSolver -nx 512 -ny 512 -i 10 -m gs -o _512.dat > _512_mem.dat
likwid-perfctr -C 0 -g CACHE -m ./pdeSolver -nx 512 -ny 512 -i 10 -m gs -o _512.dat > _512_cache.dat

likwid-perfctr -C 0 -g FLOPS_DP -m ./pdeSolver -nx 1024 -ny 1024 -i 10 -m gs -o _512.dat > _1024_flops_dp.dat
likwid-perfctr -C 0 -g MEM -m ./pdeSolver -nx 1024 -ny 1024 -i 10 -m gs -o _512.dat > _1024_mem.dat
likwid-perfctr -C 0 -g CACHE -m ./pdeSolver -nx 1024 -ny 1024 -i 10 -m gs -o _512.dat > 1024_cache.dat

likwid-perfctr -C 0 -g FLOPS_DP -m ./pdeSolver -nx 2048 -ny 2048 -i 10 -m gs -o _512.dat > _2048_flops_dp.dat
likwid-perfctr -C 0 -g MEM -m ./pdeSolver -nx 2048 -ny 2048 -i 10 -m gs -o _512.dat > _2048_mem.dat
likwid-perfctr -C 0 -g CACHE -m ./pdeSolver -nx 2048 -ny 2048 -i 10 -m gs -o _512.dat > _2048_cache.dat
