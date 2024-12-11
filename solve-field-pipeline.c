/*
 * @Author: hya yianoohh@gmail.com
 * @Date: 2024-12-11 10:35:10
 * @LastEditors: hya yianoohh@gmail.com
 * @LastEditTime: 2024-12-11 14:06:07
 * @FilePath: \undefinedc:\Users\Administrator\Desktop\b.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
solve_field.c


int main(){
    //读取FITS文件
    Reading input file;

    //调用 augment_xylist() 生成 .axy 文件
    augment_xylist;

    augment-xylist.c
    Reading FITS image to find image size;

    //Try to read WCS header from FITS image; if successful,add it to the list of WCS headers to verify.
    axy->try_verify{
        //尝试从 FITS 文件的指定扩展名读取 WCS 信息
        sip_read_header_file_ext(fitsimgfn, axy->fitsimgext, &sip) 
    }

    //Running image2xy
    image2xy_files(fitsimgfn, xylsfn, TRUE, axy->downsample, 3, axy->fitsimgext, 0, &sxyparams){
        image2xy_run{
            simplexy_run{
                //中值平滑处理
                median smoothing
                //噪声计算
                measuring image noise
                //寻找天文源
                finding objects
                //寻找峰值（峰值检测）
                finding peaks
                //在3x3中计算峰值质心
                find centroid in the 3x3 cutout 
                // 处理3x3框失败的情况，尝试使用5x5框
                find centroid in the 5x5 cutout
                // 如果在5x5框中也未能找到质心，则使用高斯拟合来估计
                max_gaussian(oimage, onx, ony, dpsf, xc[i], yc[i], &tmpxc, &tmpyc)
                //程序记录并输出找到的天文源的数量
                logmsg("simplexy: found %i sources.\n", s->npeaks);
            }
        }
    }

    //根据亮度和背景排序：根据星星的亮度和背景噪声对星表中的坐标进行排序，确保重要的天体优先
    resort_xylist() 
    //将头信息添加到 xylist，生成 axy 文件
    logverb("Writing headers to file %s\n", axy->axyfn);
    // copy blocks from xyls to output.
    logverb("Copying data block of file %s to output %s.\n", xylsfn, axy->axyfn);


    //runs astrometry-engine to actually do the solve
    run_engine(engineargs);
    //cmd : /usr/local/astrometry/bin/astrometry-engine
    run_command_get_outputs

    engine-main.c

    //reads astrometry.cfg file
    logverb("Using config file \"%s\"\n", cf);
    
    //finds index files
    engine_parse_config_file
    engine.c
    //finds index files
    index_is_file_index

    index.c
    get_filename

    engine_add_index
    //reads axy file


    //runs engine_run_job() to actually do the solve
    engine.c
    engine_run_job(engine, job)

    //parses axy file

    //based on range of image scales, selects index files to use

    onefield_run(bp)

    onefield.c

    //reads xylist
    logverb("Reading fields file %s...\n", bp->fieldfname);
    //runs any WCS headers to verify (solve-field –verify)
    for (i = 0; i < sl_size(bp->verify_wcsfiles); i++)
        logverb("verify %s\n", sl_get(bp->verify_wcsfiles, i));
    //depending on whether running with inparallel or not, loads one or all index files and calls solve_fields()
    solve_fields(bp, NULL){
        solver_preprocess_field(sp);
        solver_run()
    }

    solver.c
    
    solver_run()

    //load index files

    //compute scale ranges of field and index files
    solver_compute_quad_range

    //looks at pairs of stars A,B forming the “backbone” of the quadrangle, precomputing geometry and deciding which stars can be C,D

    //adds one star at a time, forming all quadrangles where that star is A,B or C,D, and for each index, calls add_stars()

    //add_stars() 函数负责从图像和索引中选择合适的星体，构建几何图形（四边形、三角形、五边形等）。它的功能包括：
    //函数通过选择不同的星体来构建一个或多个图形（例如四边形、三角形、五边形等），这些图形将用于匹配图像和索引文件。
    add_stars()
    
    //try_all_codes() 函数负责测试不同的星体组合，并验证它们是否符合几何约束条件。具体来说：
    //该函数尝试不同的 C, D 星体排列，并验证它们是否符合 Cx < Dx 的约束条件，即星体 C 的 x 坐标必须小于星体 D 的 x 坐标。这个约束对于保持匹配的准确性至关重要。
    try_all_codes()

    //try_all_codes_2() 函数负责尝试不同的 A 和 B 星体排列，并递归地执行一系列排列组合的测试
    //通过多次排列组合，try_all_codes_2() 会生成不同的 A 和 B 星体排列，利用这些排列构建几何图形。
    try_all_codes_2()

    //try_permutations() 是一个递归函数，负责进行进一步的排列尝试，并检查是否满足几何约束条件。它的工作流程如下：
    //递归尝试不同的 C, D 星体排列：
    //在每个递归步骤中，try_permutations() 会测试不同的 C, D 星体排列，并确保它们满足 Cx < Dx 的条件。
    //搜索匹配的 KD-tree：
    //函数会在一个名为 KD-tree 的数据结构中搜索匹配的图形。KD-tree 是一种用于高效搜索多维数据的结构，通常用于天文图像匹配中。
    try_permutations()

    //resolve_matches() 函数负责处理找到的匹配项。主要步骤如下：
    //查找匹配的索引星体编号：
    //给定一个匹配的图形（四边形或其他几何图形），resolve_matches() 会查找这些匹配图形对应的索引星体编号，确保匹配的准确性。
    //检索索引星体的 RA, Dec 坐标：
    // 在天文学中，RA（Right Ascension，赤经）和 Dec（Declination，赤纬）是用来定位星体的坐标系统。resolve_matches() 会从索引中检索与匹配的星体对应的 RA, Dec 坐标。
    // 拟合 TAN 投影：
    // 一旦匹配了图形和索引，resolve_matches() 会拟合一个 TAN（Tangent）投影模型，将图像坐标系转换为天文坐标系。
    // 调用 solver_handle_hit()：
    // 如果找到匹配，resolve_matches() 会调用 solver_handle_hit() 来处理匹配结果。
    resolve_matches()

    //  solver_handle_hit() 负责处理匹配成功后的结果。具体步骤包括：
    // 调用 verify_hit() 验证匹配：
    // 在匹配结果被返回之前，solver_handle_hit() 会调用 verify_hit() 来验证这个匹配是否符合要求。
    // 如果匹配成功，调用 solver_tweak2() 计算 SIP 系数：
    // 如果匹配有效，solver_handle_hit() 会继续调用 solver_tweak2() 来计算 SIP（Simplified Imaging Polynomial）系数，这是一个用于图像坐标和天文坐标之间转换的重要参数。
    solver_handle_hit()

    verify.c
    //searches for stars within the field in the star KD-tree
    //calls real_verify_star_lists() to do the model comparison between true match and false match.
    verify_hit()

    after_solved

    






}