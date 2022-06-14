target_sources(app
	PRIVATE main.c missing_stubs.c
	)

target_link_libraries(app
	PRIVATE liblua
	)
