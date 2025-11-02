add_rules("mode.debug", "mode.release")

add_requires("opencv 4.12.*")

target("opencv_edges")
    set_kind("binary")
    add_files("src/*.cpp")
    set_rundir(".")
    set_runargs("./images/input.jpg")
    add_packages("opencv")
