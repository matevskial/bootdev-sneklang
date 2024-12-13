project('bootdev-sneklang', 'c',
        version : '1.0.0',
        default_options : ['warning_level=3', 'c_std=c99'])

subdir('snekstack')

sources = [files('main.c')] + snekstack_sources
includes = [snekstack_inc]

bootdev_sneklang = executable(
        'bootdev_sneklang',
        sources,
        include_directories : includes,
        install : true)

test('test', bootdev_sneklang)
